import serial
import matplotlib.pyplot as plt

from CCTR_Display import Line, Oscillo


def main():

    camera = Line('camera', xr=(0, 128), yr=(-150, 150), depth=1, period=11)
    plt.draw()
    camera.figure.canvas.draw()
    # plt.show(block=False)

    i = 0
    decode = True

    f = open("frame.txt", "r")
    lines = f.readlines()
    for line in lines:
        # camera.update(line)

        if line is not None:
            if line.startswith("camera "):
                dta = line.split()
                yd = list(int(float(y)) for y in dta[1:])

        y = [val + (val - min(yd))/(max(yd) - min(yd))*2*max(yd) for val in yd]

    y_deriv = [y[k+1] - y[k-1] for k in range(2, len(y)-2)]
    y_deriv.append(0)
    y_deriv.append(0)
    y_deriv.insert(0, 0)
    y_deriv.insert(0, 0)
    camera.set(y_deriv)
    camera.draw()

    plt.show(block=True)


if __name__ == '__main__':
    main()
