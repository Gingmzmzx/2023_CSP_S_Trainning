import gmpy2

def rsa_gong_N_def(n, e1, e2, c1, c2):
    e1, e2, c1, c2, n = int(e1), int(e2), int(c1), int(c2), int(n)
    s = gmpy2.gcdext(e1, e2)
    print(s)
    s1 = s[1]
    s2 = s[2]
    if s1 < 0:
        s1 = - s1
        c1 = gmpy2.invert(c1, n)
    elif s2 < 0:
        s2 = - s2
        c2 = gmpy2.invert(c2, n)
    m = (pow(c1, s1, n) * pow(c2 ,s2 ,n)) % n
    return int(m)

with open("rsa.in", "r") as f:
    strr = f.read()
    strr = strr.split("\n")
    q = int(strr[0])
    i = 1
    while q>0:
        strrr = strr[i].split()
        with open("rsa.out", "a+") as fw:
            fw.write(str(rsa_gong_N_def(*strrr))+"\n")
        q -= 1
        i += 1