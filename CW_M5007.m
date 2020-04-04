S = linspace(100,100,12)
tmp = rand(12,1)
W = tmp * S
%W = rand(12,1) * S
%w(6,6)
w(1:6 ,1:6)=0
for(j=1:1:6)
    for(i=1:1:6)
        w(i,j) = sum( W( (i*2)-1 :i*2, (j*2)-1:j*2),'all' )/4
        % (i*2,j*2) - координаты правого нижнего угла подматрицы 2x2 в
        % матрице 12x12
        %w(i,j)=( W(2*i,2*j)+W(2*i-1,2*j)+W(2*i,2*j-1)+W(2*i-1,2*j-1) )/4
        
    end 
end

difference = sum(W,'all')- sum(w,'all')/4
