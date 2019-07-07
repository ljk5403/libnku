#!/usr/bin/env python3
"""该脚本用于libnku自动生成README.md中的目录
由于是通过遍历本地仓库生成目录,请不要在PR时运行此脚本！
维护者会定期通过此脚本更新目录。
写给维护者：
请务必确保该文件在项目文件夹内运行！
"""
import os

sourcelib="/" #GitHub支持的本仓库跳转
sourcedir=["A类课","B类课","C类课","D类课","E类课","专业攻略"]
f=open("README.md","w")


def listdir_nohidden(path):
    """仅读取非隐藏文件"""
    for f in os.listdir(path):
        if not f.startswith('.'):
            yield f

def tab_adder(level):
    string=''
    for x in range(level):
        string+="    "
    return string+"- "

def let_README_first(names):
    """将README.md放在第一个"""
    if 'README.md' in names:
        names.remove('README.md')
        names.insert(0,'README.md')

def get_dir_struct(sdir,level):
    print(tab_adder(level-1)+'['+sdir+']('+sourcelib+sdir+')',file=f)
    names = [name for name in listdir_nohidden(sdir)
            if os.path.isfile(os.path.join(sdir, name))]
    let_README_first(names)
    for x in names:
        print(tab_adder(level)+'['+x+']('+sourcelib+sdir+'/'+x+')  ',file=f)

    dirnames = [name for name in listdir_nohidden(sdir)
            if os.path.isdir(os.path.join(sdir, name))]
    for x in dirnames:
        get_dir_struct(sdir+'/'+x,level+1)


tf1=open("./template/global_readme_template1.md","r")
template1=tf1.read()
print(template1,file=f)
tf1.close()

for x in sourcedir:
    get_dir_struct(x,1)

tf2=open("./template/global_readme_template2.md","r")
template2=tf2.read()
print(template2,file=f)
tf2.close()

f.close()
