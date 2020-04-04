S = linkspace(100,100,12)
tmp = rand(12,1)
W = tmp * S
w(6,6)
for(j=1:1:6)
    for(i=1:1:6)
        w(i,j) = sum( W( (i*2)-1 :i*2, (j*2)-1:j*2) )/4
    end 
end

difference = sum(W)- sum(w)/4