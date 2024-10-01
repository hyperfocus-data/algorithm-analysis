import matplotlib.pyplot as plt
import numpy as np


def readf(filename:str) -> list:
    content: list = []
    with open(filename, "r") as f:
        content = f.readlines()
    return content

def parse_content(content: list) -> tuple:
    x: list = []
    y: list = []
    for i in content:
        if "\n" in i:
            i = i.replace("\n", "")
        x.append(i.split(":")[0])
        y.append(i.split(":")[1])
    return x, y

def makeplot(x, y, x_label: str, y_label: str, title: str, filename: str, scale=None):
    plt.figure(figsize=(12, 6))
    plt.xlabel(x_label)
    plt.ylabel(y_label)
    plt.title(title)
    plt.plot(x, y, color='r')
    if scale == 'linear':
        plt.xscale(scale)
        plt.yscale(scale)

    plt.legend()
    plt.grid()
    plt.savefig(f"{filename}.png")
    plt.close()

def plotf1(PATH: str):
    content = readf(filename=PATH)
    x = parse_content(content=content)[1] # op = 0; n = 1
    y = parse_content(content=content)[0]
    makeplot(x, y, x_label="op", y_label="n", title="f1 O(n) - C", filename="f1n9000_C", scale='linear')

def plotf2(PATH: str):
    content = readf(filename=PATH)
    x = np.linspace(0, len(parse_content(content=content)[0]), 1000)
    y = np.log2(x)
    makeplot(x, y, x_label="op", y_label="n", title="f2 log(n) - C", filename="f2n9000_C")

def plotf3(PATH: str):
    content = readf(filename=PATH)
    x = np.linspace(0, len(parse_content(content=content)[0]), 1000)
    y = x * np.log2(x)
    makeplot(x, y, x_label="op", y_label="n", title="f3 n log(n) - C", filename="f3n250000_C")

def plotf4(PATH: str):
    content = readf(filename=PATH)
    x = np.linspace(0, len(parse_content(content=content)[0]), 1000)
    y = x ** 3
    makeplot(x, y, x_label="op", y_label="n", title="f4 O(n³) - C", filename="f4n100_C")

def plotf5(PATH: str):
    content = readf(filename=PATH)
    x = np.linspace(0, len(parse_content(content=content)[0]), 1000)
    y = x ** 2
    makeplot(x, y, x_label="op", y_label="n", title="f4 O(n²) - C", filename="f5n100_C")

if __name__ == "__main__":
    PATH = "../algorithms-complexity-classification/loops/output/f1_n9000.txt"
    plotf1(PATH)

    PATH = "../algorithms-complexity-classification/loops/output/f2_n9000.txt"
    plotf2(PATH)

    PATH = "../algorithms-complexity-classification/loops/output/f3_n250000.txt"
    plotf3(PATH)

    PATH = "../algorithms-complexity-classification/loops/output/f4_n100.txt"
    plotf4(PATH)

    PATH = "../algorithms-complexity-classification/loops/output/f5_n100.txt"
    plotf5(PATH)