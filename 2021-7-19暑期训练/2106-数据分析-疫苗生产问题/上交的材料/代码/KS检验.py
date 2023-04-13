#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd
data = pd.read_excel('data2.xlsx', index_col=1, header=0, parse_dates=True)
data.drop(data.columns[0], axis=1, inplace=True)


# In[2]:


data_np=np.array(data)
data_np


# 已经转为np类型了。

# In[10]:


import copy
import scipy.stats as stats
from scipy.stats import ks_2samp


# In[12]:


ans1=np.zeros(120).reshape(3,40)
for i in range(40):
    slct=data_np[:,i]
    slct=np.sort(slct)
    M=np.max(slct)
    m=np.min(slct)
    seq=np.arange(m,M,(M-m)/50)
    print(ks_2samp(slct,seq) )
    


# In[26]:


ans2=pd.DataFrame(ans1)
ans2.to_excel('EVEN.xlsx')


# In[ ]:




