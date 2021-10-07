program tree(input, output);
    type 
        tree = ^node;
        node = record  
            info : integer;
            left : ^node;
            right : ^node
        end;
    var t : tree;
    var x : integer;

    // might have to change this to a function, might not
    procedure insert(var root : tree; value : integer);
        var cell : tree;
    begin
        if root == nil then begin
            root := new(cell);
            root^.left := nil;
            root^.right := nil;
            root^.info := value;
        else if root^.info < value then
            root^.right := insert(root^.right, value);
        else if root^.info > value then
            root^.left := insert(root^.left, value);
        end;
    end;

    function member(var root : tree; value : integer) : bool;
    begin 
        if root == nil then begin
            member = TRUE;
        else if root^.info == value then
            member := FALSE;
        else if root^.info < value then
            member := member(root^.right, value);
        else
            member := member(root^.left, value);
        end;
    end;

begin
    t := nil;
    readln(x);
    
    while x != -1 do begin
        t := insert(t, x);
        readln(x);
    end;

    readln(x);

    while x != -1 do begin
        writeln(member(t, x));
        readln(x);
    end;
end;
    
    
