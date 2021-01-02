import serial
import matplotlib.pyplot as plt
import click

from CCTR_Display import Line, Oscillo


@click.command()
@click.option(
    '--mode',
    '-m',
    default='camera',
    type=str,
    help='select what to plot'
)
@click.option(
    '--usb',
    '-u',
    default='/dev/ttyACM0',
    type=str,
    help='select the usb port'
)
def main(mode, usb):

    if mode == 'camera':
        camera = Line('camera', xr=(0, 128), yr=(-50, 260), depth=1, period=11)
        to_plot = camera

    elif mode == 'derive':
        frame = Line('derive', xr=(0, 128), yr=(-128, 128), depth=1, period=11)
        to_plot = frame

    elif mode == 'speed':
        speed = Oscillo(('S1', 'S2'), xr=(0, 128), yr=(-1, 100),
                        colors={'S1': 'red', 'S2': 'blue'},
                        labels={'S1': 'S1', 'S2': 'S2'},
                        period=1,
                        formats={'S1': float.fromhex, 'S2': float.fromhex})
        to_plot = speed

    elif mode == 'accel':
        accel = Oscillo(('X', 'Y', 'Z'), xr=(0, 128), yr=(-4000, 4000),
                        colors={'X': 'orange', 'Y': 'green', 'Z': 'black'},
                        labels={'X': 'X', 'Y': 'Y', 'Z': 'Z'},
                        period=1,
                        )
        to_plot = accel

    elif mode == 'feedback':
        feedback = Oscillo(('FBg1', 'FBg2', 'FBd1', 'FBd2'), xr=(0, 128), yr=(-1, 100),
                           colors={'FBg1': 'red', 'FBg2': 'blue', 'FBd1': 'green', 'FBd2': 'purple'},
                           labels={'FBg1': 'FBg1', 'FBg2': 'FBg2', 'FBd1': 'FBd1', 'FBd2': 'FBd2'},
                           period=1)
        to_plot = feedback

    else:
        print("Erreur de sélection du mode. Les modes valides sont: camera, derive, speed, accel, feedback")
        exit(1)

    port = serial.Serial(usb, baudrate=115200, timeout=1)

    plt.draw()
    to_plot.figure.canvas.draw()

    plt.show(block=False)
    i = 0
    decode = True

    for line in port:
        i = i + 1
        r = line
        if decode:
            r = r.decode('utf-8')
        to_plot.update(r)


if __name__ == '__main__':
    main()
