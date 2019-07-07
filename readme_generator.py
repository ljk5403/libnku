#!/usr/bin/env python3
"""该脚本用于libnku自动生成README.md中的目录
由于是通过遍历本地仓库生成目录,请不要在PR时运行此脚本！
维护者会定期通过此脚本更新目录。
写给维护者：
请务必确保该文件在项目文件夹内运行！
由于markdown语法的缘故，文件名之间的空格肯能会导致链接失效，请在push前后均检查一下！
"""
import os

sourcelib="https://github.com/ljk5403/libnku/tree/master/"
#用于README等直接展示的文档
downloadlib="https://github.com/ljk5403/libnku/raw/master/" #用于直接下载
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

def convert_to_GFM_Anchor(string):
    new_string=string
    return new_string.replace(' ','-')

def let_README_first(names):
    """将README.md放在第一个"""
    if 'README.md' in names:
        names.remove('README.md')
        names.insert(0,'README.md')

def get_dir_struct(sdir,pdir,level):
    print(tab_adder(level-1)+'['+pdir+']('+convert_to_GFM_Anchor(sourcelib+sdir)+')  ',file=f)
    names = [name for name in listdir_nohidden(sdir)
            if os.path.isfile(os.path.join(sdir, name))]
    names.sort()
    let_README_first(names)
    for x in names:
        if x.endswith(".md"):
            print(tab_adder(level)+'['+x+']('+convert_to_GFM_Anchor(sourcelib+sdir)+'/'+x+')  ',file=f)
        else:
            print(tab_adder(level)+'['+x+']('+convert_to_GFM_Anchor(downloadlib+sdir)+'/'+x+')  ',file=f)

    dirnames = [name for name in listdir_nohidden(sdir)
            if os.path.isdir(os.path.join(sdir, name))]
    dirnames.sort()
    for x in dirnames:
        get_dir_struct(sdir+'/'+x,x,level+1)


tf1=open("./template/global_readme_template1.md","r")
template1=tf1.read()
print(template1,file=f)
tf1.close()

for x in sourcedir:
    get_dir_struct(x,x,1)

tf2=open("./template/global_readme_template2.md","r")
template2=tf2.read()
print(template2,file=f)
tf2.close()

f.close()
