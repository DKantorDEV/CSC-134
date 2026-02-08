import turtle
# This is the window / GUI
window = turtle.Screen()
window.setup(width=600, height=600)
window.bgcolor("black")
window.title("CSC-134 Lab - D.K.")

# This is the turtle/pen
bob = turtle.Turtle()
bob.shape("turtle")
bob.color("red")
bob.pensize(5)
bob.speed(1)

# The "D" for my initials DK
bob.left(90)       
bob.forward(100)     
bob.right(90)         
bob.circle(-50, 180)  

# This moves over to start the "K"
bob.penup()          
bob.goto(60, 0)      
bob.setheading(90)   
bob.pendown()         

# The "K" for my initials DK
bob.forward(100)     
bob.backward(50)     
bob.right(45)      
bob.forward(70)    
bob.backward(70)     
bob.right(90)         
bob.forward(70)      

window.exitonclick()