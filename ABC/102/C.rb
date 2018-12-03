t=0;n,a=gets.to_i,gets.split.map{|i|t+=1;i.to_i-t}.sort
a.each{|i|t+=(i-a[n/2]).abs-1}
p t
