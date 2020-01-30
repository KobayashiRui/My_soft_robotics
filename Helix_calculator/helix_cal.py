import math
import sys

def helix_curvature(L,l,t): ##自然長, 測定した長さ, ズレの角度(radian)
    sita = math.asin(l/L)
    x = L * math.cos(sita)
    a = (x * 10**-3) / t
    b = (l * 10**-3) / t
    k = a / (a**2 + b**2)
    return k


if __name__ == "__main__":
    r_path = sys.argv[1]
    w_path = sys.argv[2]
    result_list = []
    with open(r_path) as f:
        for line in f:
            #一行読みこみ
            _data = [ float(data) for data in line.strip().split(",")]
            #数値へ変換
            result_list.append(str(helix_curvature(_data[0],_data[1], _data[2])))
        
    with open(w_path, mode="w") as f:
        f.write("\n".join(result_list))