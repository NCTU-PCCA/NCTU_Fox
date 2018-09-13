sum = 0

while True:
    try:
        x = int(input())
        if x==0:
            print(sum)
            sum=0
        else:
            sum += x
        
    except:
        break;
    
