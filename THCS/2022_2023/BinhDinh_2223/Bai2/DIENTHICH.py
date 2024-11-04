import math

def largestRectangle(R):
    max_area = 0

    # Loop through all possible pairs of (x1, x2) and (y1, y2)
    for x1 in range(-R, R + 1):
        for x2 in range(x1, R + 1):
            for y1 in range(-R, R + 1):
                for y2 in range(y1, R + 1):
                    # Check if all 4 corners of the rectangle are inside the circle
                    if (x1 * x1 + y1 * y1 <= R * R and
                        x2 * x2 + y1 * y1 <= R * R and
                        x1 * x1 + y2 * y2 <= R * R and
                        x2 * x2 + y2 * y2 <= R * R):
                        # Calculate the area of the rectangle
                        area = abs(x2 - x1) * abs(y2 - y1)
                        max_area = max(max_area, area)
    
    return max_area

# Read input from DIENTICH.INP
with open("DIENTICH.INP", "r") as inp_file:
    R = int(inp_file.read().strip())

# Find and output the largest rectangle area to DIENTICH.OUT
max_area = largestRectangle(R)
with open("DIENTICH.OUT", "w") as out_file:
    out_file.write(str(max_area) + "\n")
