#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
import copy
import scipy.stats as stats


# In[4]:


data = pd.read_excel('t3_in.xlsx', index_col=0, header=0, parse_dates=True)


# In[6]:


data_np=np.array(data)
data_np.shape


# In[16]:


import math


# In[15]:


import random


# In[31]:


tar=np.arange(1,100001,1).reshape(100000,1)


# In[32]:


for i in range(40):
    tmp=np.random.normal(loc=data_np[i,0],scale=math.sqrt( data_np[i,1] ),size =(100000,1) )
    tar=np.concatenate ([tar,tmp],axis=1)


# In[33]:


ans2=pd.DataFrame(tar)
ans2.to_excel('t3_data_generate.xlsx')


# In[ ]:




