import junit.framework.TestCase;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * Created by lihan on 2017/8/11.
 */
public class Base extends TestCase {

    @Before
    public void setUp() throws Exception {
        throw new Exception();
    }

    @Test
    public void testAdd() {
        assertTrue(2 == 2);
    }

    @After
    public void tearDown() throws Exception {
        System.out.println("after");
    }
}
