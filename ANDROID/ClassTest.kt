fun main() {
    val number2word = mapOf(
        0 to "zero",
        1 to "one",
        2 to "two",
        3 to "three",
        4 to "four",
        5 to "five",
        6 to "six",
        7 to "seven",
        8 to "eight",
        9 to "nine"
    )
    val n = 2
    println("$n is spelt as '${number2word[n]}'")
}