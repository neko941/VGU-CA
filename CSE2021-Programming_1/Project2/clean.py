import os
import shutil

if __name__ == '__main__':
    shutil.rmtree('result', ignore_errors=True, onerror=None)
    shutil.rmtree('template', ignore_errors=True, onerror=None)
    if os.path.exists('result.gif'): os.remove('result.gif')
    if os.path.exists('template.gif'): os.remove('template.gif')
    if os.path.exists('test.exe'): os.remove('test.exe')