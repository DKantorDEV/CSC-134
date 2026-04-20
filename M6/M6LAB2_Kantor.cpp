// =========================================================================
// M6LAB2: The Dungeon Map  —  ISS Survival
// Module 6: Arrays
// =========================================================================
//
// THEME: You're alone on a damaged space station. Find the key card
//        and reach the Bubble observation deck to signal for rescue.
//
// ASCII MAP
// ---------
//
//           [BUBBLE]
//              |
//            [LAB]               [KEY IS HERE]
//              |                       |
//  [GALLEY] - [AIRLOCK] - [SOLAR] - [ARMORY]
//      |          |
//      |       [START]
//  [REACTOR}
//
//
// THE BIG IDEA
// ------------
// This station has 7 rooms. Rooms connect via N / E / S / W.
// We need to answer: "If I'm in room X and move north, where do I go?"
//
// Answer: an ADJACENCY TABLE stored as a 2D array.
//   connections[fromRoom][direction] = destination room (or NO_CONNECTION)
//
// We ALSO use PARALLEL ARRAYS to hold each room's name, description, and
// items — all indexed the same way so roomNames[3] and roomDescriptions[3]
// both describe room 3.
//
// =========================================================================

#include <iostream>
#include <string>
using namespace std;

const int NUM_ROOMS      = 7;
const int NUM_DIRECTIONS = 4;
const int NO_CONNECTION  = -1;

// Direction indices
const int NORTH = 0;
const int EAST  = 1;
const int SOUTH = 2;
const int WEST  = 3;

// Room indices
const int AIRLOCK     = 0;
const int LAB         = 1;
const int GALLEY      = 2;
const int SOLAR       = 3;
const int REACTOR     = 4;
const int ARMORY      = 5;
const int BUBBLE      = 6;

// Items that can be found in rooms or carried by the player
enum Item { NO_ITEM, KEY };

// Function prototypes
void printRoom(string roomNames[], string roomDescriptions[], int connections[][NUM_DIRECTIONS], int room);
void printExits(int connections[][NUM_DIRECTIONS], int room);
int  commandToDirection(const string& command);

int main()
{
    // ----- Parallel arrays: all indexed by room number -----
    // Why parallel arrays instead of one big struct array?
    // Each array holds one *kind* of data about a room. That keeps array
    // types simple (string[], Item[]) and lets the 2D connections table
    // use plain int indices to cross-reference them. We'll refactor to
    // struct in a later module — for now, keeping them separate makes the
    // "indexed by room" pattern explicit.
    string roomNames[NUM_ROOMS] = {
        "Airlock",
        "Science Lab",
        "Crew Galley",
        "Solar Compartment",
        "Reactor Core",
        "Equipment Armory",
        "Bubble"
    };
    string roomDescriptions[NUM_ROOMS] = {
        "Pressurized start-point. Warning lights blink on the hatch.",
        "Dimly lit room. Samples float loose in zero-g.",
        "Ration packs drift near the ceiling. The recycler is making a sound.",
        "A tangle of solar panels. Glass glitters beyond the hull.",
        "Heat radiates from shielded fuel rods. Alarms read amber. It's very loud.",
        "Magnetic racks hold EVA tools and sealed weapons crates. A key card hangs on the wall.",
        "A bubble of glass. Earth fills the entire view below."
    };

    // ----- The adjacency table (a 2D array) -----
    // connections[fromRoom][direction] = destination room (or NO_CONNECTION).
    int connections[NUM_ROOMS][NUM_DIRECTIONS];

    // Step 1: fill every cell with NO_CONNECTION. Clean slate.
    // Nested loops visit every cell in the 2D array.
    for (int r = 0; r < NUM_ROOMS; r++)
        for (int d = 0; d < NUM_DIRECTIONS; d++)
            connections[r][d] = NO_CONNECTION;

    // Step 2: wire up the actual connections.

    connections[AIRLOCK][NORTH]  = LAB;
    connections[LAB][SOUTH]      = AIRLOCK;     // lab is directly above the airlock

    connections[AIRLOCK][SOUTH]  = GALLEY;
    connections[GALLEY][NORTH]   = AIRLOCK;     // galley is below the central hub

    connections[AIRLOCK][EAST]   = SOLAR;
    connections[SOLAR][WEST]     = AIRLOCK;     // solar array hangs off the east side

    connections[GALLEY][EAST]    = REACTOR;
    connections[REACTOR][WEST]   = GALLEY;      // reactor feeds power to the galley systems

    connections[SOLAR][EAST]     = ARMORY;
    connections[ARMORY][WEST]    = SOLAR;       // armory is at the far end of the solar truss

    connections[LAB][NORTH]      = BUBBLE;
    connections[BUBBLE][SOUTH]   = LAB;         // bubble sits on top of the lab cupola

    // ----- Items parallel array: one item -----
    Item roomItems[NUM_ROOMS];
    for (int r = 0; r < NUM_ROOMS; r++)
        roomItems[r] = NO_ITEM;
    roomItems[ARMORY] = KEY;

    // ----- Room tracking -----
    bool visited[NUM_ROOMS];
    for (int r = 0; r < NUM_ROOMS; r++)
        visited[r] = false;

    // ----- Game loop -----
    int currentRoom = AIRLOCK;
    visited[AIRLOCK]    = true;
    bool playerHasKey   = false;
    bool bubbleLocked   = true;
    string command;

    cout << "Welcome to the ISS Dungeon." << endl;
    cout << "Commands: north/n, east/e, south/s, west/w, look, quit" << endl;
    cout << "The Bubble observation deck is sealed. Find the key card to open it." << endl;

    printRoom(roomNames, roomDescriptions, connections, currentRoom);

    while (true)
    {
        cout << "\n> ";
        cin >> command;

        if (command == "quit" || command == "q")
            break;

        if (command == "look")
        {
            printRoom(roomNames, roomDescriptions, connections, currentRoom);
            if (playerHasKey)
                cout << "You are carrying: key card" << endl;
            continue;
        }

        int direction = commandToDirection(command);
        if (direction == -1)
        {
            cout << "Unknown command." << endl;
            continue;
        }

        int next = connections[currentRoom][direction];
        if (next == NO_CONNECTION)
        {
            cout << "A sealed bulkhead blocks you." << endl;
            continue;
        }

        if (next == BUBBLE && bubbleLocked)
        {
            if (!playerHasKey)
            {
                cout << "The hatch is sealed with an electronic lock. You need a key card." << endl;
                continue;
            }
            bubbleLocked = false;
            cout << "You swipe the key card. The hatch clicks open." << endl;
        }

        currentRoom = next;
        visited[currentRoom] = true;

        // Pick up any item in this room
        if (roomItems[currentRoom] == KEY)
        {
            playerHasKey = true;
            roomItems[currentRoom] = NO_ITEM;
            cout << "You pick up a key card." << endl;
        }

        printRoom(roomNames, roomDescriptions, connections, currentRoom);

        if (currentRoom == BUBBLE)
        {
            // Check whether all rooms have been visited
            bool allVisited = true;
            for (int r = 0; r < NUM_ROOMS; r++)
                if (!visited[r]) allVisited = false;

            if (allVisited)
                cout << "\nYou've reached every corner of the station. All rooms explored." << endl;
            else
                cout << "\nYou gaze at Earth from the Bubble. Some rooms still wait behind you." << endl;

            cout << "Thanks for playing." << endl;
            break;
        }
    }

    cout << "\nYou seal the airlock behind you." << endl;
    return 0;
}

// =========================================================================
// Function definitions
// =========================================================================

// Print the current room's name and description.
// Arrays come in "by reference" even though the syntax hides it —
// the compiler needs to know how wide each row is to do the math.
void printRoom(string roomNames[], string roomDescriptions[], int connections[][NUM_DIRECTIONS], int room)
{
    cout << "\n=== " << roomNames[room] << " ===" << endl;
    cout << roomDescriptions[room] << endl;
    printExits(connections, room);
}

void printExits(int connections[][NUM_DIRECTIONS], int room)
{
    const string dirNames[NUM_DIRECTIONS] = { "north", "east", "south", "west" };
    cout << "Exits: ";
    bool any = false;
    for (int d = 0; d < NUM_DIRECTIONS; d++)
    {
        if (connections[room][d] != NO_CONNECTION)
        {
            if (any) cout << ", ";
            cout << dirNames[d];
            any = true;
        }
    }
    if (!any) cout << "(none)";
    cout << endl;
}

// Turn a typed command into a direction index, or -1 if it isn't a direction.
// Keeping this in its own function means the game loop doesn't drown in
// four near-identical if/else branches.
int commandToDirection(const string& command)
{
    if (command == "north" || command == "n") return NORTH;
    if (command == "east"  || command == "e") return EAST;
    if (command == "south" || command == "s") return SOUTH;
    if (command == "west"  || command == "w") return WEST;
    return -1;
}
