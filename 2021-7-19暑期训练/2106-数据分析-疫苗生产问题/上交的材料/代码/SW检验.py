#!/usr/bin/env python
# coding: utf-8

# In[53]:


import numpy as np
import pandas as pd
data = pd.read_excel('data2.xlsx', index_col=1, header=0, parse_dates=True)
data.drop(data.columns[0], axis=1, inplace=True)


# In[54]:


data_np=np.array(data)
data_np.shape


# 已经转为np类型了。

# In[55]:


import copy
import scipy.stats as stats


# In[60]:


ans1=np.zeros(120).reshape(3,40)
for i in range(40):
    slct=data_np[i,:]
    sta,pvalue=stats.shapiro(slct)
    ans1[0,i]=sta
    ans1[1,i]=pvalue
    if (pvalue>=0.05):
        ans1[2,i]=1
    else:
        ans1[2,i]=0


# In[62]:


ans2=pd.DataFrame(ans1)
ans2.to_excel('Gauss_dealed.xlsx')


# In[58]:


print(stats.shapiro(slct))


# In[ ]:





# In[ ]:




