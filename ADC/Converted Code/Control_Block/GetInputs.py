f=open('ControlBlockInput.txt','r')
lines=f.readlines()
inputs=[]
for i in range(len(lines)):
    inputs.append(lines[i].rstrip('\n').split(","))

print str(lines).replace('[','').replace(']','').replace(',',' ').replace('\'','').replace('\\n','')

