if [ -e gtkexample ]
then
    rm gtkexample
    echo "derlenmis dosya silindi"
else
    echo "derlenmis dosya bulunamadi."
fi

echo "islem devam ediyor..."
echo "derleme baslatiliyor..."

gcc main.c -o gtkexample `pkg-config --cflags --libs gtk+-2.0`

if [ -e gtkexample ]
then
    echo "basariyla derlendi"
    read -p "Calistirilsin mi E/h:" choice
    case $choice in
    [eE]* ) ./gtkexample ;;
    [hH]* ) echo "vazgecildi" ;;
    *) exit ;;
esac

else
    echo "derleme hatasi olustu."
fi
