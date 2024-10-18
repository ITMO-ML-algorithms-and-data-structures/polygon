from generate_dataset import *

data = generate_unique_strings(100, 5, "", "()abcdeqwfjkqw()()()()()()()()")
save_dataset_to_file("dataset.txt", data, "\n")
