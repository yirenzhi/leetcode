#coding : UTF-8

zimu="abcdefghijklmnopqrstuvwxyz"
list1=[0,0,3,3,3,3,3,4,3,4]

dict_zimu={}
num=0

for i in range(2,10):
    list_zimu = []
    print(num,num+list1[i]-1)
    for j in range(num,num+list1[i]):
        list_zimu.append(zimu[j])
    dict_zimu[i]=list_zimu
    num=num+list1[i]

print (dict_zimu)
