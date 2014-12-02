#Finding the real world coordinate of robot
import math
#Finding the coordinates
xCoordinate = raw_input("What is the X coordinate of the point measured from the robot?")
yCoordinate = raw_input("What is the Y coordinate of the point measured from the robot?")
xCoordinate = float(xCoordinate)
yCoordinate = float(yCoordinate)
#Setting variables for the robot position in the world frame
xRobot = raw_input("What is the X coordinate of the robot in the world frame?")
xRobot = float(xRobot)
yRobot = raw_input("What is the Y coordinate of the robot in the world frame?")
yRobot = float(yRobot)
#Setting variable for setting the angle of the robot in respect to the origin
angle = raw_input("What is the current angle orientation of the robot in respect to the origin?")
angle = float(angle)
cosangle = math.cos(angle)
cosangle = float(cosangle)
sinangle = math.sin(angle)
sinangle = float(sinangle)

xWorld = ((xCoordinate*cosangle) - (yCoordinate*sinangle) + xRobot)
xWorld = str(xWorld)
yWorld = ((xCoordinate*sinangle) + (yCoordinate*cosangle) + yRobot)
yWorld = str(yWorld)

print "The X value of the point in the world frame is " + xWorld
print "The Y value of the point in the world frame is " + yWorld
