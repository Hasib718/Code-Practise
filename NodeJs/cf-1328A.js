var t = Number(readline());

for (var i=0; i<t; i++) {
    var a = Number(readline());
    var b = Number(readline());

    if (a%b == 0) print(0);
    else if (a < b) {
        print(b - a);
    }
    else {
        var n = 1;
        while (b >= a) {
            b = b*n
            n++;
        }
        print(b-a);
    }
}