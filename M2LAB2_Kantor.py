import turtle as t
import random

t.colormode(255)

# Make it faster!
t.speed(0) # 0 = Fastest, 1 = Slowest, 6 = normal

# Make it prettier!
t.bgcolor("black")
t.pencolor("white")

# Basic: Square
for i in range(4):
    t.forward(100)
    t.right(90)

# Evolving: Spiral
for i in range(100):
    t.forward(i * 2) # Gets bigger each time!
    t.right(91) # Not quite 90.... see what happens?

# Evolving: Rainbow Spiral
for i in range(200):
    r = random.randint(0, 255)
    g = random.randint(0, 255)
    b = random.randint(0, 255)

    t.pencolor(r, g, b)

    t.forward(i * 2)
    t.right(91)

# Turtle with boundaries
for step in range(1000):
    # Change color randomly as it moves
    r, g, b = random.randint(0, 255), random.randint(0, 255), random.randint(0, 255)
    t.pencolor(r, g, b)
    
    t.forward(10)

    # 1. Check Right Wall
    if t.xcor() > 200:
        t.setheading(180 - t.heading() + random.randint(-10, 10))
        t.setx(199) # Gently push back so it doesn't get stuck

    # 2. Check Left Wall
    if t.xcor() < -200:
        t.setheading(180 - t.heading() + random.randint(-10, 10))
        t.setx(-199)

    # 3. Check Top Wall
    if t.ycor() > 200:
        t.setheading(-t.heading() + random.randint(-10, 10))
        t.sety(199)

    # 4. Check Bottom Wall
    if t.ycor() < -200:
        t.setheading(-t.heading() + random.randint(-10, 10))
        t.sety(-199)

t.done()


# Daniel, start over, this was just a learning practice. When the semester goes on return to this and start from scratch.