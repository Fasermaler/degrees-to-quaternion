import math

# Importing time only for the speed test
import time

def to_quaternion(roll = 0.0, pitch = 0.0, yaw = 0.0):

    t0 = math.cos(math.radians(yaw * 0.5))
    t1 = math.sin(math.radians(yaw * 0.5))
    t2 = math.cos(math.radians(roll * 0.5))
    t3 = math.sin(math.radians(roll * 0.5))
    t4 = math.cos(math.radians(pitch * 0.5))
    t5 = math.sin(math.radians(pitch * 0.5))

    w = t0 * t2 * t4 + t1 * t3 * t5
    x = t0 * t3 * t4 - t1 * t2 * t5
    y = t0 * t2 * t5 + t1 * t3 * t4
    z = t1 * t2 * t4 - t0 * t3 * t5

    return [w, x, y, z]

# Speed test

start = time.time()
for i in range(360):
    w, x, y, z = to_quaternion(i, i, i)
    print("Quaternions are {:4.2f}, {:4.2f}, {:4.2f}, {:4.2f}".format(w, x, y, z))

end = time.time()

print("Python took: " + str(end - start) + " seconds.")


