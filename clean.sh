# 删除编译产生的可执行文件
for fileName in `ls`
do
    if ! echo $fileName | grep -q '\.'
    then
        rm $fileName
    fi
done