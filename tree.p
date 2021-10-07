program bst(input, output);
    type tree = ^node;
        node = record  
            info : integer;
            left : ^node;
            right : ^node
        end;
    
    var t : tree;
    var x : integer;

    procedure insert(var root : tree; value : integer);
    
    begin
        if root = nil then 
	begin
            new(root);
	    root^.left := nil;
            root^.right := nil;
            root^.info := value;
        end
        else if root^.info < value then 
            insert(root^.right, value)
        else if root^.info > value then
            insert(root^.left, value)
    end;

    function member(var root : tree; value : integer) : boolean;
    begin 
        if root = nil then begin
            member := FALSE
	end
        else if root^.info = value then
            member := TRUE
        else if root^.info < value then
            member := member(root^.right, value)
        else
            member := member(root^.left, value)
    end;

begin
    t := nil;
    readln(x);
    
    while x <> -1 do begin
        insert(t, x);
        readln(x);
    end;

    readln(x);

    while x <> -1 do begin
        writeln(member(t, x));
        readln(x);
    end;
end.
    
    
