/**
 *  Record
 * @author Yimin Xu 250876566
 *
 */
public class Record 
{
	private Key recordKey;
	private String recordData;
	
	// Constructor
	public Record(Key k, String data)
	{
		recordKey = k;
		recordData = data;
	}
	
	// Return the key of the record
	public Key getKey()
	{
		return recordKey;
	}
	
	// Return the data of the record
	public String getData()
	{
		return recordData;
	}
}
