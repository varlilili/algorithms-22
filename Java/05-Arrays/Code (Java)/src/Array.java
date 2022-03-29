public class Array<E> {

    // 类的成员变量
    private E[] data;
    private int size;
    // capacity = data.length

    // 接口，方法
    /**
     * 构造函数，传入数组的容量 capacity 构造 Array
     * @param capacity 数组的容量
     */
    public Array(int capacity){
        data = (E[])new Object[capacity];
        size = 0;
    }

    /**
     * 无参数的构造函数，默认数组的容量 capacity = 100
     */
    public Array(){
        this(100);
    }

    /**
     *
     * @return 返回数组的 size
     */
    public int getSize(){
        return size;
    }

    /**
     *
     * @return 返回数组的容量 capacity
     */
    public int getCapacity(){
        return data.length;
    }

    /**
     * 判断数组是否为空
     * @return size == 0
     */
    public boolean isEmpty(){
        return size == 0;
    }

    /**
     * 向所有元素前添加一个新元素
     * @param x 要添加的元素
     */
    public void addFirst(E x){
        add(0, x);
    }

    /**
     * 向所有元素后添加一个新元素
     * @param x 要添加的元素
     */
    public void addLast(E x){
        add(size, x);
    }

    /**
     * 在索引为 index 的位置插入一个新元素 x
     * @param index 待插入位置的索引
     * @param x 待插入元素
     */
    public void add(int index, E x){

        if(index < 0 || index > size)
            throw new IllegalArgumentException("Add failed. Require index >= 0 and index <= size");

        if(size == data.length)
            resize(2 * data.length);

        for (int i = size; i > index ; i --)
            data[i] = data[i-1];
        data[index] = x;
        size ++;
    }

    /**
     * 获取索引位置为index的元素，且通过该封装的方式，使用户无法获取未使用空间的元素，保证数据安全
     * @param index 索引位置
     * @return 位于该索引位置的元素
     */
    public E get(int index){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Get failed. Index is illegal.");
        return data[index];
    }

    /**
     * 修改 index 索引位置的元素为 x
     * @param index 待修改位置的索引
     * @param x 修改为 x 元素
     */
    public void set(int index, E x){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Get failed. Index is illegal.");
        data[index] = x;
    }

    /**
     * 查找数组中是否有元素 x
     * @param x 查询是否包含 x 元素
     * @return
     */
    public boolean contain(E x){
        for (int i = 0; i < size; i++)
            if(data[i].equals(x))
                return true;
        return false;
    }

    /**
     * 查找数组中元素 x 所在的索引，如果不存在元素 x，则返回 -1
     * @param x
     * @return
     */
    public int find(E x){
        for (int i = 0; i < size; i++) {
            if(data[i].equals(x))
                return i;
        }
        return -1;
    }

    /**
     * 从数组中删除指定元素
     * @param x
     */
    public void removeElement(E x){
        if(contain(x))
            remove(find(x));
    }

    /**
     * 从数组中删除 index 位置的元素，返回删除的元素
     * @param index
     * @return
     */
    public E remove(int index){
        if(index < 0 || index >= size)
            throw new IllegalArgumentException("Get failed. Index is illegal.");

        E ret = data[index];
        for (int i = index; i < size-1; i++)
            data[i] = data[i+1];
        size --;
        data[size] = null; // loitering objects != memory leak

        if(size == data.length / 4 && data.length / 2 != 0)
            resize(data.length / 2);
        return ret;
    }

    /**
     * 从数组中删除第一个元素，返回删除的元素
     * @return
     */
    public E removeFirst(){
        return remove(0);
    }

    /**
     * 从数组中删除最后一个元素，并返回删除的元素
     * @return
     */
    public E removeLast(){
        return remove(size - 1);
    }

    @Override
    public String toString(){
        StringBuilder res = new StringBuilder();
        res.append(String.format("Array: size = %d, capacity = %d\n", size, data.length
        ));
        res.append('[');
        for(int i = 0; i < size; i++){
            res.append(data[i]);
            if(i != size - 1)
                res.append(", ");
        }
        res.append(']');
        return res.toString();
    }

    private void resize(int newCapacity){
        E[] newData = (E[])new Object[newCapacity];
        for (int i = 0; i < size; i++)
            newData[i] = data[i];
        data = newData;
    }

}