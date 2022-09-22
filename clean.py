import os 

for root, directories, files in os.walk(os.getcwd()):
    for file in files:
        if file.endswith('.o') or file.endswith('.exe'):
            os.remove(os.path.join(root, file))
            print(f'Removed => {os.path.join(root, file)}')