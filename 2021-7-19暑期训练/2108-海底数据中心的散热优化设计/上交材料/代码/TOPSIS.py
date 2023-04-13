#!/usr/bin/env python
# coding: utf-8

# In[10]:


import numpy as np
import pandas as pd
data = pd.read_excel('data1.xlsx', parse_dates=True)


# In[11]:


data.drop(data.columns[0], axis=1, inplace=True)
data_np=np.array(data)
data_np.shape


# 第一列表示密度
# 第二列表示弹性模量
# 第三列表示抗拉强度
# 第四列表示抗压强度
# 第五列表示电势

# In[12]:


for i in range(33):
    data_np[i,0]=-data_np[i,0]


# In[ ]:


for j in range(5):
    tmp=data_np[:,j];
    ave=tmp.mean();
    dx=np.sqrt( np.var(tmp) );
    for i in range(33):
        data_np[i,j]=(data_np[i,j]-ave)/( dx )


# In[ ]:


tar=np.zeros(5)
for j in range(5):
    for i in range(33):
        tar[j]=max( tar[j] , data_np[i,j] )


# In[ ]:


out=np.zeros(33)
for i in range(33):
    for j in range(5):
        out[i]=out[i]+data_np[i,j]


# In[ ]:


ans2=pd.DataFrame(out)
ans2.to_excel('data2.xlsx')


# In[ ]:




