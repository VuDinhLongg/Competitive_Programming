# 📖 BurgerRestaurant - Giải Thích Code Chi Tiết

> **Tài liệu này giải thích từng dòng code, từng hàm, từng class trong dự án BurgerRestaurant**

---

## 📑 Mục Lục

- [1. Item.java - Lớp Cơ Sở Trừu Tượng](#1-itemjava---lớp-cơ-sở-trừu-tượng)
- [2. Burger.java - Lớp Burger](#2-burgerjava---lớp-burger)
- [3. DeluxeBurger.java - Lớp Burger Cao Cấp](#3-deluxeburgerjava---lớp-burger-cao-cấp)
- [4. Drink.java - Lớp Đồ Uống](#4-drinkjava---lớp-đồ-uống)
- [5. SideItem.java - Lớp Món Phụ](#5-sideitemjava---lớp-món-phụ)
- [6. MealOrder.java - Lớp Quản Lý Đơn Hàng](#6-mealorderjava---lớp-quản-lý-đơn-hàng)
- [7. Main.java - Entry Point](#7-mainjava---entry-point)

---

## 1. Item.java - Lớp Cơ Sở Trừu Tượng

### 📄 Full Code

```java
package com.burgers.item;

public abstract class Item {
    protected String name;
    protected String type;
    protected double price;

    public Item(String name, String type, double price) {
        this.name = name;
        this.type = type;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getBasePrice() {
        return price;
    }

    public double getAdjustedPrice() {
        return price;
    }

    public void printItem() {
        System.out.printf("%-20s $%5.2f%n", getName(), getAdjustedPrice());
    }
}
```

---

### 🎯 Mục Đích Class

**Item** là lớp trừu tượng (abstract class) đóng vai trò là **lớp cha chung** cho tất cả các món ăn trong hệ thống.

**Tại sao cần class này?**
- ✅ Tránh lặp code: Tất cả món ăn đều có `name`, `type`, `price`
- ✅ Polymorphism: Có thể xử lý tất cả món ăn thông qua interface chung
- ✅ Extensibility: Dễ dàng thêm món ăn mới chỉ cần extends Item

---

### 📦 Package Declaration

```java
package com.burgers.item;
```

**Giải thích:**
- Khai báo class này thuộc package `com.burgers.item`
- Package giúp tổ chức code theo chức năng
- Tránh xung đột tên class

**Cấu trúc thư mục tương ứng:**
```
src/com/burgers/item/Item.java
```

---

### 🏗️ Class Declaration

```java
public abstract class Item {
```

**Phân tích từng keyword:**

| Keyword | Ý Nghĩa | Lý Do Sử Dụng |
|---------|---------|---------------|
| `public` | Class có thể truy cập từ bất kỳ đâu | Để các package khác có thể import |
| `abstract` | Không thể tạo instance trực tiếp | "Món ăn" quá chung chung, phải cụ thể hóa |
| `class` | Định nghĩa một class | Đây là blueprint cho objects |
| `Item` | Tên class | Đại diện cho một món ăn |

**Ví dụ:**
```java
// ❌ KHÔNG THỂ làm thế này:
Item item = new Item("Burger", "Food", 5.0); // Lỗi: Item is abstract

// ✅ PHẢI làm thế này:
Item item = new Burger("Beef", 5.0); // OK: Burger extends Item
```

---

### 🔧 Thuộc Tính (Attributes)

```java
protected String name;
protected String type;
protected double price;
```

#### Thuộc Tính 1: `name`

**Khai báo:**
```java
protected String name;
```

**Phân tích:**
- **`protected`**: Cho phép class con truy cập trực tiếp
  - Không phải `private`: Lớp con cần đọc/ghi
  - Không phải `public`: Bảo vệ khỏi truy cập ngoài ý muốn
- **`String`**: Kiểu dữ liệu chuỗi
- **`name`**: Tên món ăn (VD: "Beef Burger", "Coke", "Fries")

**Ví dụ sử dụng:**
```java
// Trong constructor của Burger
this.name = "Beef Burger"; // Truy cập được vì protected

// Trong class bên ngoài
// item.name = "xxx"; // ❌ Lỗi: protected không cho phép
```

---

#### Thuộc Tính 2: `type`

**Khai báo:**
```java
protected String type;
```

**Phân tích:**
- Phân loại món ăn: "Burger", "Drink", "Side", "Topping"
- Giúp phân biệt các loại món trong hệ thống
- Hữu ích cho việc filtering hoặc reporting

**Giá trị có thể:**
```java
"Burger"   // Bánh burger
"Drink"    // Đồ uống
"Side"     // Món phụ
"Topping"  // Topping cho burger
```

---

#### Thuộc Tính 3: `price`

**Khai báo:**
```java
protected double price;
```

**Phân tích:**
- **`double`**: Số thực có độ chính xác cao
  - Phù hợp cho tiền tệ (VD: $5.99)
  - Hỗ trợ số thập phân
- **`price`**: Giá gốc của món ăn

**Tại sao không dùng `int`?**
```java
int price = 5;      // ❌ Không biểu diễn được $5.50
double price = 5.5; // ✅ Chính xác
```

**Tại sao không dùng `float`?**
```java
float price = 5.99f;   // ❌ Độ chính xác thấp hơn
double price = 5.99;   // ✅ Độ chính xác cao hơn
```

---

### 🏗️ Constructor

```java
public Item(String name, String type, double price) {
    this.name = name;
    this.type = type;
    this.price = price;
}
```

#### Phân Tích Chi Tiết

**Signature:**
```java
public Item(String name, String type, double price)
```

| Phần | Ý Nghĩa |
|------|---------|
| `public` | Các class con có thể gọi qua `super()` |
| `Item` | Tên constructor trùng với tên class |
| `(String name, ...)` | Nhận 3 tham số đầu vào |

**Body:**
```java
this.name = name;
```

**Giải thích `this`:**
- `this.name`: Thuộc tính của object (bên trái)
- `name`: Tham số của constructor (bên phải)
- `this` phân biệt giữa thuộc tính và tham số cùng tên

**Minh họa:**
```java
// Khi gọi:
Item item = new Burger("Beef", "Burger", 5.50);

// Thực thi:
this.name = "Beef";     // thuộc tính name = tham số name
this.type = "Burger";   // thuộc tính type = tham số type
this.price = 5.50;      // thuộc tính price = tham số price
```

**Tại sao cần constructor này?**
- ✅ Khởi tạo giá trị ban đầu cho object
- ✅ Đảm bảo mọi Item đều có name, type, price
- ✅ Lớp con gọi qua `super(name, type, price)`

---

### 📝 Method 1: getName()

```java
public String getName() {
    return name;
}
```

#### Phân Tích

**Signature:**
```java
public String getName()
```

| Phần | Ý Nghĩa |
|------|---------|
| `public` | Có thể gọi từ bất kỳ đâu |
| `String` | Kiểu dữ liệu trả về |
| `getName` | Tên method (theo convention JavaBean) |
| `()` | Không nhận tham số |

**Body:**
```java
return name;
```

**Mục đích:**
- **Getter method**: Truy cập thuộc tính `name` từ bên ngoài
- **Encapsulation**: Không cho phép truy cập trực tiếp `item.name`

**Ví dụ sử dụng:**
```java
Item burger = new Burger("Beef", 5.50);
String itemName = burger.getName(); // "Beef"
System.out.println(itemName);       // In ra: Beef
```

**Tại sao không để `name` là `public`?**
```java
// Cách 1: BAD - Không encapsulation
public String name;
item.name = ""; // ❌ Có thể gán giá trị rỗng

// Cách 2: GOOD - Có kiểm soát
public String getName() {
    return name;
}
// Có thể thêm validation, logging, etc.
```

---

### 📝 Method 2: getBasePrice()

```java
public double getBasePrice() {
    return price;
}
```

#### Phân Tích

**Signature:**
```java
public double getBasePrice()
```

| Phần | Ý Nghĩa |
|------|---------|
| `public` | Public access |
| `double` | Trả về số thực |
| `getBasePrice` | Lấy giá gốc (chưa điều chỉnh) |

**Body:**
```java
return price;
```

**Tại sao gọi là "Base" Price?**
- **Base Price** = Giá gốc, chưa thêm phụ phí
- **Adjusted Price** = Giá sau khi điều chỉnh (topping, size, etc.)

**So sánh:**
```java
Burger burger = new Burger("Beef", 5.00);
burger.addTopping("Cheese", 0.50);

burger.getBasePrice();      // 5.00  (giá gốc)
burger.getAdjustedPrice();  // 5.50  (giá + topping)
```

**Ví dụ thực tế:**
```java
// Menu hiển thị giá gốc
System.out.println("Beef Burger: $" + burger.getBasePrice());

// Hóa đơn hiển thị giá thực
System.out.println("Total: $" + burger.getAdjustedPrice());
```

---

### 📝 Method 3: getAdjustedPrice()

```java
public double getAdjustedPrice() {
    return price;
}
```

#### Phân Tích

**Signature:**
```java
public double getAdjustedPrice()
```

**Tại sao method này quan trọng?**
- 🎯 **Polymorphism điểm chính của dự án**
- 🎯 Mỗi loại món có cách tính giá khác nhau
- 🎯 Lớp con override để customize

**Implementation mặc định:**
```java
return price; // Trả về giá gốc
```

**Override ở các lớp con:**

| Class | Cách Tính Giá |
|-------|---------------|
| `Item` | `price` (giá gốc) |
| `Burger` | `price + tổng giá topping` |
| `DeluxeBurger` | `price` (cố định) |
| `Drink` | `price + phụ phí size` |
| `SideItem` | `price` (không thay đổi) |

**Ví dụ Polymorphism:**
```java
List<Item> items = new ArrayList<>();
items.add(new Burger("Beef", 5.00));
items.add(new Drink("Coke", 1.50));
items.add(new SideItem("Fries", 2.00));

// Tính tổng - mỗi item tự tính giá theo cách riêng
double total = 0;
for (Item item : items) {
    total += item.getAdjustedPrice(); // Polymorphic call
}
```

**Flow diagram:**
```
item.getAdjustedPrice()
    ↓
Kiểm tra runtime type
    ↓
├─ Nếu Burger    → Gọi Burger.getAdjustedPrice()    → giá + topping
├─ Nếu Drink     → Gọi Drink.getAdjustedPrice()     → giá + size
└─ Nếu SideItem  → Gọi Item.getAdjustedPrice()      → giá gốc
```

---

### 📝 Method 4: printItem()

```java
public void printItem() {
    System.out.printf("%-20s $%5.2f%n", getName(), getAdjustedPrice());
}
```

#### Phân Tích Chi Tiết

**Signature:**
```java
public void printItem()
```

| Phần | Ý Nghĩa |
|------|---------|
| `public` | Public access |
| `void` | Không trả về giá trị |
| `printItem` | In thông tin món ăn |

**Body - Format String:**
```java
System.out.printf("%-20s $%5.2f%n", getName(), getAdjustedPrice());
```

#### Giải Thích `printf` Format

**Cú pháp:**
```java
printf(format_string, arguments...)
```

**Format String Breakdown:**
```
"%-20s $%5.2f%n"
  ↓     ↓  ↓  ↓
  1     2  3  4
```

**Phần 1: `%-20s`**
```
%      - Bắt đầu format specifier
-      - Canh trái (left-align)
20     - Chiều rộng 20 ký tự
s      - String type
```

**Ví dụ:**
```java
printf("%-20s", "Burger");
// Output: "Burger              " (15 spaces sau)

printf("%-20s", "Deluxe Beef Burger");
// Output: "Deluxe Beef Burger  " (2 spaces sau)
```

**Phần 2: `$` - Literal**
```
$ - In ký tự $ ra màn hình
```

**Phần 3: `%5.2f`**
```
%      - Bắt đầu format specifier
5      - Tổng chiều rộng (bao gồm dấu chấm và số thập phân)
.2     - 2 chữ số thập phân
f      - Float/Double type
```

**Ví dụ:**
```java
printf("%5.2f", 5.5);
// Output: " 5.50" (1 space trước, 2 số thập phân)

printf("%5.2f", 12.99);
// Output: "12.99" (đủ 5 ký tự)
```

**Phần 4: `%n`**
```
%n - Newline (xuống dòng)
     Platform-independent (\n trên Unix, \r\n trên Windows)
```

#### Ví Dụ Hoàn Chỉnh

**Code:**
```java
Item burger = new Burger("Beef", 5.50);
burger.printItem();
```

**Output:**
```
Beef Burger          $ 5.50
```

**Phân tích output:**
```
"Beef Burger          $ 5.50"
 ↑                  ↑   ↑
 ├─ "Beef Burger"   │   └─ 5.50 (2 chữ số thập phân)
 ├─ 10 spaces       │
 └─ Tổng 20 ký tự   └─ Literal '$'
```

#### So Sánh `println` vs `printf`

**Cách 1: Dùng `println` - UGLY**
```java
public void printItem() {
    System.out.println(getName() + " $" + getAdjustedPrice());
}
// Output: "Beef Burger $5.5" ❌ Không aligned, 1 số thập phân
```

**Cách 2: Dùng `printf` - BEAUTIFUL**
```java
public void printItem() {
    System.out.printf("%-20s $%5.2f%n", getName(), getAdjustedPrice());
}
// Output: "Beef Burger          $ 5.50" ✅ Aligned, 2 số thập phân
```

#### Tại Sao Override printItem()?

**Template Method Pattern:**
- Item định nghĩa **template** (format cơ bản)
- Lớp con override để **customize** (thêm chi tiết)

**Ví dụ:**
```java
// Item.java
public void printItem() {
    System.out.printf("%-20s $%5.2f%n", getName(), getAdjustedPrice());
}

// Burger.java
@Override
public void printItem() {
    super.printItem();  // In burger
    // Thêm chi tiết toppings
    for (Item topping : toppings) {
        System.out.printf(" -> %-15s $%5.2f%n", 
            topping.getName(), topping.getBasePrice());
    }
}
```

**Output:**
```
Beef Burger          $ 5.50
 -> Cheese           $ 0.50
 -> Bacon            $ 1.00
```

---

### 📊 Tổng Kết Class Item

#### Class Diagram

```
┌─────────────────────────────────┐
│         Item (abstract)         │
├─────────────────────────────────┤
│ - name: String                  │
│ - type: String                  │
│ - price: double                 │
├─────────────────────────────────┤
│ + Item(name, type, price)       │
│ + getName(): String             │
│ + getBasePrice(): double        │
│ + getAdjustedPrice(): double    │
│ + printItem(): void             │
└─────────────────────────────────┘
```

#### Mối Quan Hệ

```
Item (abstract)
  ↑
  ├── Burger (extends)
  │     ↑
  │     └── DeluxeBurger (extends)
  ├── Drink (extends)
  └── SideItem (extends)
```

---

## 2. Burger.java - Lớp Burger

### 📄 Full Code

```java
package com.burgers.item;

import java.util.ArrayList;
import java.util.List;

public class Burger extends Item {
    private List<Item> toppings;
    private int maxToppings;

    public Burger(String name, double price) {
        super(name, "Burger", price);
        this.maxToppings = 3;
        this.toppings = new ArrayList<>();
    }

    protected Burger(String name, double price, int maxToppings) {
        super(name, "Burger", price);
        this.maxToppings = maxToppings;
        this.toppings = new ArrayList<>();
    }

    public void addTopping(String name, double price) {
        if (toppings.size() < maxToppings) {
            toppings.add(new Item(name, "Topping", price) {});
        } else {
            System.out.println("Cannot add topping: Maximum number of toppings reached.");
        }
    }

    @Override
    public double getAdjustedPrice() {
        double adjustedPrice = super.getBasePrice();
        for (Item topping : toppings) {
            adjustedPrice += topping.getAdjustedPrice();
        }
        return adjustedPrice;
    }

    @Override
    public void printItem() {
        System.out.printf("%-20s $%5.2f%n", getName() + " Burger", getBasePrice());
        for (Item topping : toppings) {
            System.out.printf(" -> %-15s $%5.2f%n", topping.getName(), topping.getBasePrice());
        }
    }
}
```

---

### 🎯 Mục Đích Class

**Burger** đại diện cho món burger có thể **tùy chỉnh** bằng cách thêm topping.

**Đặc điểm:**
- ✅ Extends từ `Item` (kế thừa thuộc tính và method)
- ✅ Quản lý danh sách topping
- ✅ Giới hạn số lượng topping tối đa
- ✅ Tính giá = giá gốc + tổng giá topping

---

### 📦 Import Statements

```java
import java.util.ArrayList;
import java.util.List;
```

#### Giải Thích

**Import 1: `ArrayList`**
```java
import java.util.ArrayList;
```

**Mục đích:**
- Import class `ArrayList` từ package `java.util`
- `ArrayList` là implementation của `List` interface
- Dùng để lưu danh sách topping

**Tại sao cần import?**
```java
// ❌ Không import - Lỗi
List<Item> toppings = new ArrayList<>(); // Cannot resolve symbol 'ArrayList'

// ✅ Có import - OK
import java.util.ArrayList;
List<Item> toppings = new ArrayList<>(); // OK
```

**Import 2: `List`**
```java
import java.util.List;
```

**Mục đích:**
- Import interface `List` từ package `java.util`
- Dùng làm kiểu dữ liệu cho `toppings`

**Tại sao dùng `List` interface thay vì `ArrayList`?**
```java
// ❌ BAD - Coupling to implementation
ArrayList<Item> toppings = new ArrayList<>();

// ✅ GOOD - Program to interface
List<Item> toppings = new ArrayList<>();
```

**Lợi ích:**
- Dễ thay đổi implementation sau này
- Flexible và maintainable
- Best practice trong Java

---

### 🏗️ Class Declaration

```java
public class Burger extends Item {
```

#### Phân Tích

| Keyword | Ý Nghĩa |
|---------|---------|
| `public` | Class có thể truy cập từ mọi nơi |
| `class` | Định nghĩa class |
| `Burger` | Tên class |
| `extends` | Kế thừa từ class khác |
| `Item` | Lớp cha |

**Ý nghĩa `extends Item`:**
- Burger **IS-A** Item (Burger là một Item)
- Kế thừa tất cả thuộc tính và method của Item
- Có thể override method để customize behavior

**Diagram:**
```
      Item
       ↑
       │ extends
       │
     Burger
```

**Burger có gì từ Item?**
```java
// Kế thừa từ Item:
protected String name;        // ✅
protected String type;        // ✅
protected double price;       // ✅
public String getName()       // ✅
public double getBasePrice()  // ✅

// Thêm mới trong Burger:
private List<Item> toppings;  // 🆕
private int maxToppings;      // 🆕
```

---

### 🔧 Thuộc Tính

```java
private List<Item> toppings;
private int maxToppings;
```

#### Thuộc Tính 1: `toppings`

**Khai báo:**
```java
private List<Item> toppings;
```

**Phân tích:**
- **`private`**: Chỉ Burger class truy cập được
  - Không để `protected`: DeluxeBurger không cần truy cập trực tiếp
  - Encapsulation tốt nhất
- **`List<Item>`**: Danh sách các Item
  - Generic type `<Item>`: Chỉ chứa Item hoặc subclass của Item
  - Interface `List`: Flexible, có thể đổi implementation
- **`toppings`**: Tên biến - danh sách topping

**Tại sao `List<Item>` thay vì `List<String>`?**
```java
// ❌ BAD - Chỉ lưu tên, mất thông tin giá
List<String> toppings = Arrays.asList("Cheese", "Bacon");

// ✅ GOOD - Lưu cả tên và giá
List<Item> toppings = new ArrayList<>();
toppings.add(new Item("Cheese", "Topping", 0.50) {});
```

**Ví dụ sử dụng:**
```java
// Thêm topping
toppings.add(new Item("Cheese", "Topping", 0.50) {});

// Duyệt topping
for (Item topping : toppings) {
    System.out.println(topping.getName() + ": $" + topping.getBasePrice());
}

// Số lượng topping
int count = toppings.size();
```

---

#### Thuộc Tính 2: `maxToppings`

**Khai báo:**
```java
private int maxToppings;
```

**Phân tích:**
- **`private`**: Chỉ Burger truy cập
- **`int`**: Số nguyên
- **`maxToppings`**: Số lượng topping tối đa cho phép

**Mục đích:**
- **Business rule**: Giới hạn số topping khách có thể thêm
- **Validation**: Kiểm tra trước khi thêm topping
- **Flexibility**: Có thể khác nhau giữa Burger và DeluxeBurger

**Giá trị:**
```java
Regular Burger:  maxToppings = 3
Deluxe Burger:   maxToppings = 5
```

**Logic sử dụng:**
```java
if (toppings.size() < maxToppings) {
    // OK - Còn chỗ, thêm được
    toppings.add(...);
} else {
    // FULL - Đã đủ, từ chối
    System.out.println("Cannot add more toppings");
}
```

---

### 🏗️ Constructor 1 (Public)

```java
public Burger(String name, double price) {
    super(name, "Burger", price);
    this.maxToppings = 3;
    this.toppings = new ArrayList<>();
}
```

#### Phân Tích Từng Dòng

**Dòng 1: Signature**
```java
public Burger(String name, double price)
```

| Phần | Ý Nghĩa |
|------|---------|
| `public` | Bất kỳ ai cũng có thể tạo Burger |
| `Burger` | Tên constructor = tên class |
| `String name` | Tham số 1: Tên burger |
| `double price` | Tham số 2: Giá burger |

**Ví dụ gọi:**
```java
Burger burger = new Burger("Beef", 5.50);
//                         ↑      ↑
//                       name   price
```

---

**Dòng 2: super() Call**
```java
super(name, "Burger", price);
```

**Giải thích `super()`:**
- Gọi constructor của lớp cha (`Item`)
- Phải là **dòng đầu tiên** trong constructor
- Khởi tạo thuộc tính của Item

**Truyền tham số:**
```java
super(name,      "Burger",    price);
      ↓          ↓            ↓
   name từ    Cố định      price từ
   tham số    "Burger"     tham số
```

**Flow:**
```
new Burger("Beef", 5.50)
     ↓
Burger constructor
     ↓
super("Beef", "Burger", 5.50)
     ↓
Item constructor
     ↓
this.name = "Beef";
this.type = "Burger";
this.price = 5.50;
     ↓
Quay lại Burger constructor
```

**Tại sao cố định `"Burger"`?**
```java
// Burger luôn có type là "Burger"
super(name, "Burger", price); // ✅ Type = "Burger"

// Không cho phép thay đổi type
super(name, "Drink", price);  // ❌ Sai logic
```

---

**Dòng 3: Khởi Tạo maxToppings**
```java
this.maxToppings = 3;
```

**Giải thích:**
- Gán giá trị `3` cho thuộc tính `maxToppings`
- Regular burger chỉ được 3 topping
- Hard-coded value (có thể tách thành constant)

**Cải tiến có thể:**
```java
private static final int DEFAULT_MAX_TOPPINGS = 3;

public Burger(String name, double price) {
    super(name, "Burger", price);
    this.maxToppings = DEFAULT_MAX_TOPPINGS;
    this.toppings = new ArrayList<>();
}
```

---

**Dòng 4: Khởi Tạo ArrayList**
```java
this.toppings = new ArrayList<>();
```

**Giải thích:**
- Tạo instance mới của `ArrayList`
- Gán vào thuộc tính `toppings`
- Ban đầu danh sách rỗng (0 topping)

**Phân tích:**
```java
this.toppings = new ArrayList<>();
↑             ↑   ↑            ↑
│             │   │            └─ Diamond operator (type inference)
│             │   └─ Tạo instance mới
│             └─ Assignment operator
└─ Thuộc tính của object hiện tại
```

**Diamond operator `<>`:**
```java
// Java 7+: Type inference
List<Item> toppings = new ArrayList<>(); // ✅ Ngắn gọn

// Java 6-: Phải khai báo đầy đủ
List<Item> toppings = new ArrayList<Item>(); // ✅ Dài dòng
```

**Tại sao phải khởi tạo?**
```java
// ❌ Không khởi tạo - NULL POINTER EXCEPTION
private List<Item> toppings;

public void addTopping(...) {
    toppings.add(...); // ❌ NullPointerException!
}

// ✅ Khởi tạo trong constructor
this.toppings = new ArrayList<>();
```

---

### 🏗️ Constructor 2 (Protected)

```java
protected Burger(String name, double price, int maxToppings) {
    super(name, "Burger", price);
    this.maxToppings = maxToppings;
    this.toppings = new ArrayList<>();
}
```

#### Phân Tích

**Signature:**
```java
protected Burger(String name, double price, int maxToppings)
```

| Phần | Ý Nghĩa |
|------|---------|
| `protected` | Chỉ class con (DeluxeBurger) gọi được |
| `Burger` | Constructor name |
| `int maxToppings` | Tham số thứ 3 - số topping tối đa |

**Tại sao `protected`?**
- ✅ Cho phép `DeluxeBurger` gọi qua `super(name, price, 5)`
- ✅ Không cho phép code bên ngoài gọi trực tiếp
- ✅ Encapsulation tốt hơn

**So sánh 2 constructors:**

| Constructor | Access | Parameters | Ai Dùng? |
|-------------|--------|------------|----------|
| Constructor 1 | `public` | `name, price` | Client code |
| Constructor 2 | `protected` | `name, price, maxToppings` | DeluxeBurger |

**Ví dụ:**
```java
// ✅ Client code - Dùng public constructor
Burger burger = new Burger("Beef", 5.50);
// maxToppings tự động = 3

// ❌ Client code - KHÔNG THỂ gọi protected constructor
Burger burger = new Burger("Beef", 5.50, 5); // Compile error

// ✅ DeluxeBurger - Dùng protected constructor
public class DeluxeBurger extends Burger {
    public DeluxeBurger(String name, double price) {
        super(name, price, 5); // OK - DeluxeBurger có 5 toppings
    }
}
```

**Dòng quan trọng:**
```java
this.maxToppings = maxToppings;
```

**Khác với constructor 1:**
- Constructor 1: Hard-code `maxToppings = 3`
- Constructor 2: Flexible, nhận từ tham số

---

### 📝 Method: addTopping()

```java
public void addTopping(String name, double price) {
    if (toppings.size() < maxToppings) {
        toppings.add(new Item(name, "Topping", price) {});
    } else {
        System.out.println("Cannot add topping: Maximum number of toppings reached.");
    }
}
```

#### Phân Tích Chi Tiết

**Signature:**
```java
public void addTopping(String name, double price)
```

| Phần | Ý Nghĩa |
|------|---------|
| `public` | Bất kỳ ai cũng có thể thêm topping |
| `void` | Không trả về giá trị |
| `addTopping` | Tên method |
| `String name` | Tên topping (VD: "Cheese") |
| `double price` | Giá topping (VD: 0.50) |

---

**Dòng 1: Kiểm Tra Điều Kiện**
```java
if (toppings.size() < maxToppings) {
```

**Phân tích:**
- `toppings.size()`: Số topping hiện tại
- `<`: Nhỏ hơn
- `maxToppings`: Số topping tối đa cho phép
- Điều kiện: Còn chỗ để thêm topping

**Ví dụ:**
```java
// Burger có maxToppings = 3
toppings.size() = 0  < 3  → true  → Thêm được
toppings.size() = 1  < 3  → true  → Thêm được
toppings.size() = 2  < 3  → true  → Thêm được
toppings.size() = 3  < 3  → false → FULL, không thêm
```

---

**Dòng 2: Thêm Topping (Anonymous Class)**
```java
toppings.add(new Item(name, "Topping", price) {});
```

**ĐÂY LÀ ĐOẠN CODE QUAN TRỌNG NHẤT!**

**Phân tích từng phần:**

**Phần 1: `toppings.add(...)`**
- Gọi method `add()` của `ArrayList`
- Thêm element vào cuối danh sách

**Phần 2: `new Item(...) {}`**
- **Anonymous class** (lớp vô danh)
- Tạo instance từ abstract class `Item`
- `{}` rỗng = không override method nào

**Tại sao có thể `new Item()` khi Item là abstract?**

```java
// ❌ KHÔNG THỂ tạo instance trực tiếp
Item item = new Item("Cheese", "Topping", 0.50); // Compile error

// ✅ CÓ THỂ tạo anonymous class
Item item = new Item("Cheese", "Topping", 0.50) {}; // OK
//                                                 ↑↑
//                                    Dấu {} làm nó thành anonymous class
```

**Anonymous class là gì?**
```java
// Tương đương với:
class AnonymousTopping extends Item {
    public AnonymousTopping(String name, String type, double price) {
        super(name, type, price);
    }
    // Không override gì
}

Item topping = new AnonymousTopping("Cheese", "Topping", 0.50);
```

**Tại sao dùng anonymous class?**
- ✅ Topping không cần logic đặc biệt
- ✅ Chỉ cần lưu name và price
- ✅ Ngắn gọn, không cần tạo class `Topping` riêng
- ✅ One-time use

**Có thể thêm override:**
```java
toppings.add(new Item(name, "Topping", price) {
    @Override
    public double getAdjustedPrice() {
        // Custom logic cho topping
        return super.getAdjustedPrice() * 1.1; // +10% VAT
    }
});
```

---

**Dòng 3-5: Xử Lý Khi FULL**
```java
} else {
    System.out.println("Cannot add topping: Maximum number of toppings reached.");
}
```

**Business logic:**
- Từ chối thêm topping
- In thông báo lỗi ra console
- Không throw exception

**Cải tiến có thể:**
```java
// Cách 1: Return boolean
public boolean addTopping(String name, double price) {
    if (toppings.size() < maxToppings) {
        toppings.add(new Item(name, "Topping", price) {});
        return true;  // Thành công
    }
    return false;  // Thất bại
}

// Cách 2: Throw exception
public void addTopping(String name, double price) throws MaxToppingsException {
    if (toppings.size() >= maxToppings) {
        throw new MaxToppingsException("Cannot add more toppings");
    }
    toppings.add(new Item(name, "Topping", price) {});
}
```

---

#### Ví Dụ Sử Dụng addTopping()

**Ví dụ 1: Thêm thành công**
```java
Burger burger = new Burger("Beef", 5.00);

burger.addTopping("Cheese", 0.50);  // OK - topping 1/3
burger.addTopping("Bacon", 1.00);   // OK - topping 2/3
burger.addTopping("Lettuce", 0.25); // OK - topping 3/3

System.out.println(burger.getAdjustedPrice());
// Output: 6.75 (5.00 + 0.50 + 1.00 + 0.25)
```

**Ví dụ 2: Thêm vượt quá**
```java
Burger burger = new Burger("Beef", 5.00);

burger.addTopping("Cheese", 0.50);   // OK
burger.addTopping("Bacon", 1.00);    // OK
burger.addTopping("Lettuce", 0.25);  // OK
burger.addTopping("Tomato", 0.30);   // ❌ FULL
// Output: "Cannot add topping: Maximum number of toppings reached."

System.out.println(burger.getAdjustedPrice());
// Output: 6.75 (Tomato không được thêm)
```

---

### 📝 Method: getAdjustedPrice() - Override

```java
@Override
public double getAdjustedPrice() {
    double adjustedPrice = super.getBasePrice();
    for (Item topping : toppings) {
        adjustedPrice += topping.getAdjustedPrice();
    }
    return adjustedPrice;
}
```

#### Phân Tích Chi Tiết

**Annotation:**
```java
@Override
```

**Mục đích `@Override`:**
- Báo cho compiler biết đang override method của lớp cha
- Compile error nếu method không tồn tại trong lớp cha
- Best practice: Luôn dùng `@Override`

**Ví dụ:**
```java
@Override
public double getAdjustedPrice() { ... } // ✅ OK

@Override
public double getAdjustPrice() { ... }   // ❌ Typo → Compile error
```

---

**Signature:**
```java
public double getAdjustedPrice()
```

**So sánh với Item:**
```java
// Item.java (lớp cha)
public double getAdjustedPrice() {
    return price; // Chỉ trả về giá gốc
}

// Burger.java (lớp con)
@Override
public double getAdjustedPrice() {
    return price + tổng giá topping; // Giá gốc + topping
}
```

---

**Dòng 1: Lấy Giá Gốc**
```java
double adjustedPrice = super.getBasePrice();
```

**Phân tích:**
- `super`: Tham chiếu đến lớp cha (Item)
- `getBasePrice()`: Method của Item, trả về `price`
- Khởi tạo biến `adjustedPrice` với giá gốc burger

**Tại sao dùng `super.getBasePrice()`?**
```java
// Cách 1: Dùng super (GOOD)
double adjustedPrice = super.getBasePrice(); // ✅ Rõ ràng

// Cách 2: Dùng this (OK nhưng không rõ)
double adjustedPrice = this.getBasePrice();  // ✅ Cũng OK

// Cách 3: Truy cập trực tiếp (BEST nếu price là protected)
double adjustedPrice = this.price;           // ✅ Nhanh nhất
```

**Trong trường hợp này:**
```java
double adjustedPrice = super.getBasePrice();
// Tương đương:
double adjustedPrice = this.price; // Vì price là protected
```

---

**Dòng 2-4: For-Each Loop**
```java
for (Item topping : toppings) {
    adjustedPrice += topping.getAdjustedPrice();
}
```

**Cú pháp for-each:**
```java
for (Type variable : collection) {
    // Use variable
}
```

**Phân tích:**
- `Item topping`: Biến tạm, mỗi vòng lặp = 1 topping
- `:`: "in" (topping trong toppings)
- `toppings`: Collection cần duyệt
- Loop qua **TẤT CẢ** topping trong danh sách

**Tương đương với:**
```java
// For-each (ngắn gọn)
for (Item topping : toppings) {
    adjustedPrice += topping.getAdjustedPrice();
}

// Traditional for loop (dài dòng)
for (int i = 0; i < toppings.size(); i++) {
    Item topping = toppings.get(i);
    adjustedPrice += topping.getAdjustedPrice();
}

// Iterator (phức tạp)
Iterator<Item> it = toppings.iterator();
while (it.hasNext()) {
    Item topping = it.next();
    adjustedPrice += topping.getAdjustedPrice();
}
```

---

**Dòng trong loop:**
```java
adjustedPrice += topping.getAdjustedPrice();
```

**Phân tích:**
- `+=`: Compound assignment operator
- `adjustedPrice = adjustedPrice + topping.getAdjustedPrice()`
- Cộng dồn giá của từng topping

**Flow:**
```java
// Ban đầu
adjustedPrice = 5.00 (giá burger)

// Topping 1: Cheese ($0.50)
adjustedPrice = 5.00 + 0.50 = 5.50

// Topping 2: Bacon ($1.00)
adjustedPrice = 5.50 + 1.00 = 6.50

// Topping 3: Lettuce ($0.25)
adjustedPrice = 6.50 + 0.25 = 6.75

// Return
return 6.75;
```

---

**Dòng 5: Return**
```java
return adjustedPrice;
```

**Trả về:**
- Tổng giá = Giá burger + Tổng giá toppings
- Đây chính là giá khách phải trả

---

#### Ví Dụ Hoàn Chỉnh

**Code:**
```java
Burger burger = new Burger("Beef", 5.00);
burger.addTopping("Cheese", 0.50);
burger.addTopping("Bacon", 1.00);
burger.addTopping("Lettuce", 0.25);

double basePrice = burger.getBasePrice();
double finalPrice = burger.getAdjustedPrice();

System.out.println("Base: $" + basePrice);
System.out.println("Final: $" + finalPrice);
```

**Output:**
```
Base: $5.0
Final: $6.75
```

**Trace qua code:**
```java
getAdjustedPrice() được gọi
    ↓
adjustedPrice = super.getBasePrice() = 5.00
    ↓
Loop topping 1: "Cheese" ($0.50)
    adjustedPrice = 5.00 + 0.50 = 5.50
    ↓
Loop topping 2: "Bacon" ($1.00)
    adjustedPrice = 5.50 + 1.00 = 6.50
    ↓
Loop topping 3: "Lettuce" ($0.25)
    adjustedPrice = 6.50 + 0.25 = 6.75
    ↓
return 6.75
```

---

### 📝 Method: printItem() - Override

```java
@Override
public void printItem() {
    System.out.printf("%-20s $%5.2f%n", getName() + " Burger", getBasePrice());
    for (Item topping : toppings) {
        System.out.printf(" -> %-15s $%5.2f%n", topping.getName(), topping.getBasePrice());
    }
}
```

#### Phân Tích Chi Tiết

**Dòng 1: In Burger**
```java
System.out.printf("%-20s $%5.2f%n", getName() + " Burger", getBasePrice());
```

**Phần 1: `getName() + " Burger"`**
```java
getName()          // "Beef" (từ Item)
+ " Burger"        // Thêm chữ " Burger"
= "Beef Burger"    // Kết quả
```

**Tại sao thêm `" Burger"`?**
- Để phân biệt với các món khác
- Output đẹp hơn: "Beef Burger" thay vì "Beef"

**Phần 2: `getBasePrice()`**
- Hiển thị giá gốc của burger (không bao gồm topping)
- Topping sẽ được in riêng ở dưới

---

**Dòng 2-4: In Từng Topping**
```java
for (Item topping : toppings) {
    System.out.printf(" -> %-15s $%5.2f%n", topping.getName(), topping.getBasePrice());
}
```

**Format đặc biệt:**
```java
" -> %-15s $%5.2f%n"
 ↑↑
 Thụt lề để phân biệt topping
```

**Output mẫu:**
```
Beef Burger          $ 5.00
 -> Cheese           $ 0.50
 -> Bacon            $ 1.00
 -> Lettuce          $ 0.25
```

**Phân tích format:**
- `" -> "`: Prefix để nhận biết đây là topping
- `%-15s`: Tên topping, canh trái, 15 ký tự
- `$%5.2f`: Giá topping

---

#### So Sánh Item.printItem() vs Burger.printItem()

**Item.printItem() (lớp cha):**
```java
public void printItem() {
    System.out.printf("%-20s $%5.2f%n", getName(), getAdjustedPrice());
}
```
**Output:**
```
Beef                 $ 6.75
```

**Burger.printItem() (lớp con - override):**
```java
@Override
public void printItem() {
    System.out.printf("%-20s $%5.2f%n", getName() + " Burger", getBasePrice());
    for (Item topping : toppings) {
        System.out.printf(" -> %-15s $%5.2f%n", topping.getName(), topping.getBasePrice());
    }
}
```
**Output:**
```
Beef Burger          $ 5.00
 -> Cheese           $ 0.50
 -> Bacon            $ 1.00
 -> Lettuce          $ 0.25
```

**Khác biệt:**
- Item: In 1 dòng, giá tổng
- Burger: In nhiều dòng, chi tiết từng topping

---

### 📊 Tổng Kết Class Burger

#### Class Diagram

```
┌─────────────────────────────────────────────┐
│              Burger extends Item            │
├─────────────────────────────────────────────┤
│ - toppings: List<Item>                      │
│ - maxToppings: int                          │
├─────────────────────────────────────────────┤
│ + Burger(name, price)                       │
│ # Burger(name, price, maxToppings)          │
│ + addTopping(name, price): void             │
│ + getAdjustedPrice(): double                │
│ + printItem(): void                         │
└─────────────────────────────────────────────┘
```

#### Mối Quan Hệ

```
Item (abstract)
  ↑
  │ extends
  │
Burger
  ↑
  │ uses (composition)
  │
List<Item> toppings
```

---

## 3. DeluxeBurger.java - Lớp Burger Cao Cấp

### 📄 Full Code

```java
package com.burgers.item;

public class DeluxeBurger extends Burger {

    public DeluxeBurger(String name, double price) {
        super(name, price, 5);
    }

    @Override
    public double getAdjustedPrice() {
        return super.getBasePrice();
    }

    @Override
    public void printItem() {
        super.printItem();
        System.out.println("   (Price includes toppings, drink and side item)");
    }
}
```

---

### 🎯 Mục Đích Class

**DeluxeBurger** là burger **cao cấp** với các đặc điểm:
- ⭐ Cho phép **5 topping** (thay vì 3)
- ⭐ **Giá cố định** dù thêm bao nhiêu topping
- ⭐ Giá đã **bao gồm** drink và side item
- ⭐ **Package deal** - combo khuyến mãi

**Business logic:**
```
Regular Burger: $5.00 + $0.50 (Cheese) + $1.00 (Bacon) = $6.50
Deluxe Burger:  $10.00 (cố định, dù có 5 toppings)
```

---

### 🏗️ Class Declaration

```java
public class DeluxeBurger extends Burger {
```

**Hierarchy:**
```
Item (abstract)
  ↑
  │ extends
  │
Burger
  ↑
  │ extends
  │
DeluxeBurger
```

**Kế thừa:**
- DeluxeBurger **IS-A** Burger
- DeluxeBurger **IS-A** Item
- Kế thừa tất cả từ Burger và Item

**Điều DeluxeBurger có:**
```java
// Từ Item:
protected String name;
protected String type;
protected double price;
public String getName();
public double getBasePrice();

// Từ Burger:
private List<Item> toppings;
private int maxToppings;
public void addTopping(...);

// Override trong DeluxeBurger:
public double getAdjustedPrice();  // 🔄 Thay đổi logic
public void printItem();            // 🔄 Thêm message
```

---

### 🏗️ Constructor

```java
public DeluxeBurger(String name, double price) {
    super(name, price, 5);
}
```

#### Phân Tích

**Signature:**
```java
public DeluxeBurger(String name, double price)
```

**Tham số:**
- `String name`: Tên burger (VD: "Deluxe")
- `double price`: Giá trọn gói (VD: 10.00)

---

**Dòng duy nhất:**
```java
super(name, price, 5);
```

**Giải thích:**
- Gọi **protected constructor** của Burger
- Truyền `5` cho `maxToppings`

**So sánh:**
```java
// Regular Burger
Burger burger = new Burger("Beef", 5.00);
    ↓
super(name, "Burger", price);
this.maxToppings = 3;  // Hard-coded

// Deluxe Burger
DeluxeBurger deluxe = new DeluxeBurger("Deluxe", 10.00);
    ↓
super(name, price, 5);  // Truyền 5
    ↓
super(name, "Burger", price);
this.maxToppings = 5;  // Từ tham số
```

**Tại sao truyền `5`?**
- Business rule: Deluxe burger cho phép 5 topping
- Khuyến mãi đặc biệt
- Tăng giá trị cho khách

---

**Flow khởi tạo:**
```
new DeluxeBurger("Deluxe", 10.00)
    ↓
DeluxeBurger constructor
    ↓
super("Deluxe", 10.00, 5)
    ↓
Burger protected constructor
    ↓
super("Deluxe", "Burger", 10.00)
    ↓
Item constructor
    ↓
this.name = "Deluxe";
this.type = "Burger";
this.price = 10.00;
    ↓
Quay về Burger constructor
    ↓
this.maxToppings = 5;
this.toppings = new ArrayList<>();
    ↓
Quay về DeluxeBurger constructor
    ↓
(Không có code thêm)
    ↓
Object DeluxeBurger được tạo xong
```

---

### 📝 Method: getAdjustedPrice() - Override Quan Trọng

```java
@Override
public double getAdjustedPrice() {
    return super.getBasePrice();
}
```

#### ĐÂY LÀ METHOD QUAN TRỌNG NHẤT CỦA DELUXEBURGER!

**Phân tích:**

**So sánh 3 cách tính giá:**

| Class | Method | Cách Tính |
|-------|--------|-----------|
| `Item` | `getAdjustedPrice()` | `return price;` |
| `Burger` | `getAdjustedPrice()` | `return price + tổng topping;` |
| `DeluxeBurger` | `getAdjustedPrice()` | `return price;` (cố định) |

---

**Dòng duy nhất:**
```java
return super.getBasePrice();
```

**Giải thích:**
- `super`: Gọi method của lớp cha (Burger hoặc Item)
- `getBasePrice()`: Trả về thuộc tính `price`
- **Bỏ qua** logic cộng topping trong `Burger.getAdjustedPrice()`

**Tại sao không gọi `super.getAdjustedPrice()`?**
```java
// ❌ Nếu gọi super.getAdjustedPrice()
@Override
public double getAdjustedPrice() {
    return super.getAdjustedPrice(); // Gọi Burger.getAdjustedPrice()
}

// → Sẽ tính: price + tổng topping
// → KHÔNG ĐÚNG với business logic của Deluxe


// ✅ Gọi super.getBasePrice()
@Override
public double getAdjustedPrice() {
    return super.getBasePrice(); // Bỏ qua logic topping
}

// → Chỉ trả về price
// → ĐÚNG: Giá cố định
```

---

**Ví dụ minh họa:**

```java
// Regular Burger
Burger burger = new Burger("Beef", 5.00);
burger.addTopping("Cheese", 0.50);
burger.addTopping("Bacon", 1.00);
System.out.println(burger.getAdjustedPrice());
// Output: 6.50 (5.00 + 0.50 + 1.00)

// Deluxe Burger
DeluxeBurger deluxe = new DeluxeBurger("Deluxe", 10.00);
del
