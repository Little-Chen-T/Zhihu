import torch
import time

a = torch.zeros(1,10)

b = torch.rand(10,1)

# for i in range(len(b)):
#     b[i] = i
    
len_b = len(b)

c = torch.sub(b.transpose(1,0)[:,:len_b-1], b[:len_b-3,:])

print(c.shape)

b = b.transpose(1,0)[:,1:len_b]

e = b.clone()

for i in range(len_b-4):
    e = torch.cat((e,b),0)
    
print(e.shape)


print(e)
print(b)

d = torch.where(c<=0.01, 1,0 )

f = torch.where(c<=0.01, torch.FloatTensor(e), torch.zeros(1,1))
print(f)

print(d)

print(torch.triu(d))

print(torch.triu(d).sum(1))

print(torch.argmax(torch.triu(d).sum(1)))

max_idx = torch.argmax(torch.triu(d).sum(1))

print(torch.triu(f))

g = torch.triu(f)[max_idx]

print(g)

h = torch.nonzero(g)

print(h)

i = g[h]

print(i.transpose(0,1)[0])
    
