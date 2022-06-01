import sys 
sys.path.append("C:\\Users\\riku3\\anaconda3\\lib\\site-packages")
import matlab.engine
eng = matlab.engine.start_matlab()
t = eng.gcd(100.0,80.0,nargout=3)
print(t)