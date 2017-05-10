
public class SelfTest 
{
	public static void main(String[] args) throws DictionaryException
	{
		OrderedDictionary dict2 = new OrderedDictionary();
		
		String[] words = {"C","B","A","E","D"};
		Key[] keys = new Key[10];
 		Record [] records = new Record[10];
		for (int i = 0; i < 5; i ++)
		{
			keys[i] = new Key(words[i],1);
			records[i] = new Record(keys[i],words[i]);
			dict2.insert(records[i]);

		}

		
	}
}
