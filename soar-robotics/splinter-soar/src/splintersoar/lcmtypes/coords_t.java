package splintersoar.lcmtypes;
 
import java.io.*;
import java.util.*;
 
public class coords_t implements lcm.lcm.LCMEncodable
{
    public long utime;
    public double xy[];
 
    public coords_t()
    {
        xy = new double[2];
    }
 
    public static final long LCM_FINGERPRINT;
    public static final long LCM_FINGERPRINT_BASE = 0xc4330d3b6f88e805L;
 
    static {
        LCM_FINGERPRINT = _hashRecursive(new ArrayList<Class>());
    }
 
    public static long _hashRecursive(ArrayList<Class> classes)
    {
        if (classes.contains(splintersoar.lcmtypes.coords_t.class))
            return 0L;
 
        classes.add(splintersoar.lcmtypes.coords_t.class);
        long hash = LCM_FINGERPRINT_BASE
            ;
        classes.remove(classes.size() - 1);
        return (hash<<1) + ((hash>>63)&1);
    }
 
    public void encode(DataOutputStream outs) throws IOException
    {
        outs.writeLong(LCM_FINGERPRINT);
        _encodeRecursive(outs);
    }
 
    public void _encodeRecursive(DataOutputStream outs) throws IOException
    {
        byte[] __strbuf = null;
        outs.writeLong(this.utime); 
 
        for (int a = 0; a < 2; a++) {
            outs.writeDouble(this.xy[a]); 
        }
 
    }
 
    public coords_t(DataInputStream ins) throws IOException
    {
        if (ins.readLong() != LCM_FINGERPRINT)
            throw new IOException("LCM Decode error: bad fingerprint");
 
        _decodeRecursive(ins);
    }
 
    public static splintersoar.lcmtypes.coords_t _decodeRecursiveFactory(DataInputStream ins) throws IOException
    {
        splintersoar.lcmtypes.coords_t o = new splintersoar.lcmtypes.coords_t();
        o._decodeRecursive(ins);
        return o;
    }
 
    public void _decodeRecursive(DataInputStream ins) throws IOException
    {
        byte[] __strbuf = null;
        this.utime = ins.readLong();
 
        this.xy = new double[(int) 2];
        for (int a = 0; a < 2; a++) {
            this.xy[a] = ins.readDouble();
        }
 
    }
 
    public splintersoar.lcmtypes.coords_t copy()
    {
        splintersoar.lcmtypes.coords_t outobj = new splintersoar.lcmtypes.coords_t();
        outobj.utime = this.utime;
 
        outobj.xy = new double[(int) 2];
        for (int a = 0; a < 2; a++) {
            outobj.xy = this.xy;
        }
 
        return outobj;
    }
 
}

