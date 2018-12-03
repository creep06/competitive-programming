n = gets.to_i
ok = 0
(0..100).each{|i| ok = 1 if i*4<=n && (n-i*4)%7==0}
puts ok==1 ? "Yes" : "No"
