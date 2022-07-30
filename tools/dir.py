import os
import sys
import shutil

def Create_Dir(Floder):
    try:
        os.mkdir(Floder)
    except:
        pass

def Delete_Dir(Floder,DisErr):
    try:
        shutil.rmtree(Floder)
    except Exception as Errinfo:
        if not DisErr:
            raise Errinfo

if __name__=='__main__':
    Parameter=sys.argv[1]
    Floder=sys.argv[2]
    DisErr=False
    if 'DisErr':
        DisErr=True
    
    if Parameter=='mkdir':
        Create_Dir(Floder)
    elif Parameter=='rmdir':
        Delete_Dir(Floder,DisErr)
    else:
        raise Exception("无效参数'{a}'".format(a=Parameter))