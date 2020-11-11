import java.util.{Date, Locale}
import java.text.DateFormat._

object UKDate {
  def main(args: Array[String]): Unit = {
    val now = new Date
    val df = getDateInstance(LONG, Locale.UK)
    println(df format now)
  }
}