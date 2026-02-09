import turtle

# The screen window parameters
screen = turtle.Screen()
screen.bgcolor("black")
screen.setup(width=1200, height=600)

t = turtle.Turtle()
t.speed(20)
t.pensize(3)

# Starting coordinates
start_x = -450
start_y = 120

colors = ["red", "white", "blue"]

# Loop through each color (3 lines total)
for row, color in enumerate(colors):
    t.color(color)
    
    # Resets the offset so not everything gets overlapped
    offset = start_x
    # Moves the next rows Y position lower
    current_y = start_y - (row * 150)
    
    for i in range(6):
        # Area to draw "D""
        t.penup()
        t.goto(offset, current_y)
        t.setheading(90) # Always face up for "normal" look
        t.pendown()

        # Draw the "D"
        t.forward(100)     
        t.right(90)         
        t.circle(-50, 180)  

        # Area to draw "K"
        t.penup()          
        t.goto(offset + 70, current_y) 
        t.setheading(90)   
        t.pendown()         

        # Draw the "K"
        t.forward(100)     
        t.backward(50)     
        t.right(45)      
        t.forward(70)    
        t.backward(70)     
        t.right(90)         
        t.forward(70)

        # Space between DK so not each one are overlapping
        offset += 160

t.hideturtle()
screen.mainloop()