class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s)!=len(t)):
            return False
        dicts={}
        dictt={}
        for i in s:
            if dicts.get(i):
                dicts[i]+=1
            else:
                dicts[i]=1
        for j in t:
            if dictt.get(j):
                dictt[j]+=1
            else:
                dictt[j]=1
        
        for k,v in dicts.items():
            if v != dictt.get(k):
                return False
        return True

        
            
        