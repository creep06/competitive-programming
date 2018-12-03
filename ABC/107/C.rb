n,k=gets.split.map(&:to_i)
x=gets.split.map(&:to_i)
r=1<<30
(n-k+1).times{|i|
	a,b=x[i],x[i+k-1]
	s,l=[a.abs,b.abs].sort
	r=[r,a*b<0 ? s*2+l : l].min
}
p r
