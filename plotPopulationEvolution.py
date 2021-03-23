import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

stats = pd.read_csv("report.csv")
columns = stats.columns
print(columns)

behaviour_stack = []
behaviour_headers = []
AccessoriesAndCaptors_stack = []
AccessoriesAndCaptors_headers = []

for c in columns:
    if c[:2] == "b_":
        behaviour_headers.append(c)
        behaviour_stack.append(stats[c].values.tolist())
    elif (c[:2] == "a_") or (c[:2] == "c_"):
        AccessoriesAndCaptors_headers.append(c)
        AccessoriesAndCaptors_stack.append(stats[c].values.tolist())
behaviour_stack = np.vstack(behaviour_stack)
# AccessoriesAndCaptors_stack = np.vstack(AccessoriesAndCaptors_stack)

# First plot
fig, ax = plt.subplots(1, 1, figsize=(45, 50))
ax = plt.gca()
ax.stackplot(range(1, len(stats) + 1), behaviour_stack, labels=behaviour_headers, alpha=0.7)
ax.set_title("Evolution of population with behaviour distinction.", fontsize=18)
ax.legend(fontsize=10, ncol=4)
plt.xlabel("Number of steps.")
plt.ylabel("Number of Animals.")

# Second plot
fig, ax = plt.subplots(1, 1, figsize=(45, 50))
ax = plt.gca()
ax.stackplot(range(1, len(stats) + 1), behaviour_stack, labels=behaviour_headers, alpha=0.7)
ax.set_title("Evolution of accessories and captors population.", fontsize=18)
ax.legend(fontsize=10, ncol=4)
plt.xlabel("Number of steps.")
plt.ylabel("Number of accessories and captors.")

plt.show()
