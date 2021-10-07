program tree\(input, output);
    type 
        tree = ^node;
        node = record  
            info : integer;
            left : ^node;
            right : ^node
        end;
    // might have to change this to a function, might not
    procedure insert(var root : tree; value : integer);
        var cell : tree;
    begin
        if root == nil then begin
            root = new(cell);
            root^.left = nil;
            root^.right = nil;
            root^.info := value;
        else if root^.info < value then
            root^.right = insert(root^.right, value);
        else if root^.info > value then
            root^.left = insert(root^.left, value);
        end;
    end;

    function member(var root : tree; value : integer);
    begin 
        if root == nil then begin
            member = 0;
        else if root^.info == value then
            member = 1;
        else if root^.info < value then
            member = member(root^.right, value);
        else
            member = member(root^.left, value);
        end;
    end;