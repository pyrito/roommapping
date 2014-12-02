import math
#Read the file given by the robot

output_file = open("output.txt", "r+")

with open("corner4.txt", 'r') as input_file:
    for line in input_file:

        if line[0] == '!':
            temp = line[1:]
            xRobot, yRobot, psi = [float(i) for i in temp.split()]
            #print 'xRobot = %s, yRobot = %s, psi = %s' %(xRobot, yRobot, psi)  

        else:   
            yaw, pitch, r = [float(i) for i in line.split()]
            x = r * math.cos(math.radians(yaw)) * math.sin(math.radians(pitch))
            y = r * math.sin(math.radians(yaw)) * math.sin(math.radians(pitch))
            z = r * math.cos(math.radians(pitch))
            #print 'x = %.2f, y = %.2f, z = %.2f\n' %(x, y, z) 

            xWorld = ((x * math.cos(math.radians(psi))) - (y * math.sin(math.radians(psi))) + xRobot)
            yWorld = ((x * math.sin(math.radians(psi))) + (y * math.cos(math.radians(psi))) + yRobot)
            zWorld = z + 10  #Sensor is 10 cm off ground

            print '%.2f, %.2f, %.2f' %(xWorld, yWorld, zWorld)  
            #output_file.write(xWorld + ',' + yWorld + ',' + zWorld + '\n') 

input_file.close()
output_file.close()