import os
import sys
import argparse
import subprocess
import imageio.v2 as imageio

def install(package):
    subprocess.check_call([sys.executable, "-m", "pip", "install", package])

def parse_opt():
    parser = argparse.ArgumentParser()
    parser.add_argument('-i', '--input', type=str, help='path to directory of images')
    return parser.parse_args()

if __name__ == '__main__':
    # install('imageio')
    opt = parse_opt()
    filesPath = opt.input
    filenames = os.listdir(filesPath)
    images = []
    for filename in filenames:
        images.append(imageio.imread(os.path.join(filesPath, filename)))
    imageio.mimsave(f'{filesPath}.gif', images)
    print(f"Save to: {filesPath}.gif")