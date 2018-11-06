package com.wooddeep;

import com.hazelcast.core.Hazelcast;
import com.hazelcast.core.HazelcastInstance;

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

// java -cp .:/Users/lihan/Downloads/ccalljava/hazelcast-3.8.2.jar  com.migu.sdk.GateWay

public class HZ {

    List values;

    public HZ() {
        values = new ArrayList();
    }

    public void addValue(String v) {
        values.add(v);
    }

    public int getSize() {
        return values.size();
    }

    public void printValues() {

        Function<String, Integer> cb = (str) -> {
            System.out.println(str);
            return 0;
        };

        cb.apply("in the com.migu.tsg package!");
        HazelcastInstance hc1 = Hazelcast.newHazelcastInstance();
        HazelcastInstance hc2 = Hazelcast.newHazelcastInstance();
        hc1.getMap("testcache").put("name", "andy");
        System.out.println(hc1.getMap("testcache").get("name"));
        System.out.println(hc2.getMap("testcache").get("name"));

        cb.apply("this string is xxx!");
    }

    // 集群管理参考 SdkStormWeb.java
    public static void main(String[] args) {
        HazelcastInstance hc1 = Hazelcast.newHazelcastInstance();
        HazelcastInstance hc2 = Hazelcast.newHazelcastInstance();
        hc1.getMap("testcache").put("name", "andy");
        System.out.println(hc1.getMap("testcache").get("name"));
        System.out.println(hc2.getMap("testcache").get("name"));
    }
}

