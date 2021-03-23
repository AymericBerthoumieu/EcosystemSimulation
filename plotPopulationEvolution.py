import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from os import listdir


def find_csv_filenames(path_to_dir, suffix=".csv"):
    """
    :param path_to_dir: path to the directory where you are looking fore files
    :param suffix: file type
    :return:
    list of names of files of type suffix in directory at path_to_dir
    """
    filenames = listdir(path_to_dir)
    return [filename for filename in filenames if filename.endswith(suffix)]


csvFiles = find_csv_filenames('./')  # All .csv files in the current directory

# Plot for each .csv file (or simulation)
for i in range(len(csvFiles)):
    stats = pd.read_csv(csvFiles[i])  # read file
    columns = stats.columns  # take headers

    behaviour_stack = []
    behaviour_headers = []
    AccessoriesAndCaptors_stack = []
    AccessoriesAndCaptors_headers = []

    for c in columns:
        if c[:2] == "b_":
            behaviour_headers.append(c)  # behaviours' headers
            behaviour_stack.append(stats[c].values.tolist())  # behaviours' data
        elif (c[:2] == "a_") or (c[:2] == "c_"):
            AccessoriesAndCaptors_headers.append(c)  # accessories and captors' headers
            AccessoriesAndCaptors_stack.append(stats[c].values.tolist())  # accessories and captors' data
    behaviour_stack = np.vstack(behaviour_stack)
    # AccessoriesAndCaptors_stack = np.vstack(AccessoriesAndCaptors_stack)

    # First plot (behaviour and full population)
    fig, ax = plt.subplots(1, 1, figsize=(45, 50))
    ax = plt.gca()
    ax.stackplot(range(1, len(stats) + 1), behaviour_stack, labels=behaviour_headers, alpha=0.7)
    title = "Evolution of population with behaviour distinction. (simulation " + str(i + 1) + "/" + str(
        len(csvFiles)) + ")"
    ax.set_title(title, fontsize=18)
    ax.legend(fontsize=10)
    plt.xlabel("Number of steps.")
    plt.ylabel("Number of Animals.")

    # Second plot (accesories and captors)
    """
    fig, ax = plt.subplots(1, 1, figsize=(45, 50))
    ax = plt.gca()
    ax.stackplot(range(1, len(stats) + 1), AccessoriesAndCaptors_stack, labels=AccessoriesAndCaptors_headers, alpha=0.7)
    title = "Evolution of accessories and captors population.(simulation " + str(i + 1) + "/" + str(len(csvFiles)) + ")"
    ax.set_title(title, fontsize=18)
    ax.legend(fontsize=10)
    plt.xlabel("Number of steps.")
    plt.ylabel("Number of accessories and captors.")
    """

    plt.show()
