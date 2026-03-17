import kotlin.io.println

// 1. 父类：必须标记为 open 才能被继承
open class SmartDevice(val name: String, val category: String) {
    
    var deviceStatus = "Unknown"

    init {
        println("父类主构造函数：正在初始化 $name")
    }

    // 父类的辅助构造函数：处理带状态码的情况
    constructor(name: String, category: String, statusCode: Int) : this(name, category) {
        deviceStatus = if (statusCode == 1) "Online" else "Offline"
        println("父类辅助构造函数：设置状态为 $deviceStatus")
    }
}

// 2. 子类：继承父类
// 注意：子类的主构造函数 必须 调用父类的主构造函数
class SmartLight(
    name: String, 
    val brightness: Int = 100 // 子类特有的属性
) : SmartDevice(name, "Light") { // 这里固定了 category 为 "Light"

    init {
        println("子类主构造函数：亮度设为 $brightness")
    }

    // 子类的辅助构造函数：为了兼容旧逻辑或者特殊输入
    // 它必须通过 this(...) 调用自己的主构造函数，进而间接调用父类主构造函数
    constructor(name: String, brightness: Int, statusCode: Int) : this(name, brightness) {
        this.deviceStatus = if (statusCode == 1) "Online" else "Offline"
        println("子类辅助构造函数：处理状态码")
    }

    // 3. 伴生对象：地道的工厂模式
    companion object {
        fun createPurpleLight(name: String): SmartLight {
            println("工厂方法：正在生产特殊的紫色灯...")
            return SmartLight(name, 80)
        }
    }
}

// --- 测试运行 ---
fun main() {
    println("--- 场景1：使用子类主构造函数 ---")
    val light1 = SmartLight("客厅大灯", 90)

    println("\n--- 场景2：使用子类辅助构造函数 ---")
    val light2 = SmartLight("卧室小灯", 50, 0)

    println("\n--- 场景3：使用工厂方法（推荐） ---")
    val light3 = SmartLight.createPurpleLight("氛围灯")
}