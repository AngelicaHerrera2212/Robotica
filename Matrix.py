import cv2
import numpy as np

def draw_matrix(image, matrix_rows, matrix_cols, top_offset, bottom_offset, left_offset, right_offset):
    # Calculate the size of each cell based on the image dimensions, matrix size, and offsets
    cell_width = (image.shape[1] - left_offset - right_offset) // matrix_cols
    cell_height = (image.shape[0] - top_offset - bottom_offset) // matrix_rows

    # Draw the matrix on top of the image
    for i in range(matrix_rows):
        for j in range(matrix_cols):
            # Calculate the coordinates for the current cell
            x1 = left_offset + j * cell_width
            y1 = top_offset + i * cell_height
            x2 = left_offset + (j + 1) * cell_width
            y2 = top_offset + (i + 1) * cell_height

            # Draw the rectangle for the current cell
            cv2.rectangle(image, (x1, y1), (x2, y2), (0, 255, 0), 2)  # Change the color (0, 255, 0) and thickness (2) as desired

    return image

def cut_cells(image, matrix_rows, matrix_cols, top_offset, bottom_offset, left_offset, right_offset):
    # Calculate the size of each cell based on the image dimensions, matrix size, and offsets
    cell_width = (image.shape[1] - left_offset - right_offset) // matrix_cols
    cell_height = (image.shape[0] - top_offset - bottom_offset) // matrix_rows

    # Cut each cell and create a new image for each cell
    for i in range(matrix_rows):
        for j in range(matrix_cols):
            # Calculate the coordinates for the current cell
            x1 = left_offset + j * cell_width
            y1 = top_offset + i * cell_height
            x2 = left_offset + (j + 1) * cell_width
            y2 = top_offset + (i + 1) * cell_height

            # Cut the current cell from the image
            cell = image[y1:y2, x1:x2]

            # Save the cell as a separate image
            cv2.imshow(f"cell_{i}_{j}.jpg", cell)  # Change the file format (.jpg) and naming convention as desired

im_name = "Table_Pics Rev02\Foto #2.jpg"

# Load the existing image
image = cv2.imread(im_name)  # Replace 'path_to_your_image.jpg' with the actual path to your image file
matrix = np.copy(image)


# Define the matrix properties
matrix_rows = 5
matrix_cols = 5

# Define the offsets
top_offset = 50
bottom_offset = 50
left_offset = 50
right_offset = 50

# Draw the matrix on top of the image
image_with_matrix = draw_matrix(matrix, matrix_rows, matrix_cols, top_offset, bottom_offset, left_offset, right_offset)

# Cut each cell and create separate images
cut_cells(image, matrix_rows, matrix_cols, top_offset, bottom_offset, left_offset, right_offset)

# Display the modified image with the matrix overlaid
cv2.imshow("Matrix Image", image_with_matrix)
cv2.waitKey(0)
cv2.destroyAllWindows()