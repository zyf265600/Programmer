<template>
  <section class="jumbotron">
    <h3 class="jumbotron-heading">Search Github Users</h3>
    <div>
      <input
        type="text"
        placeholder="enter the name you search"
        v-model="keyWord"
      />&nbsp;<button @click="searchUsers">Search</button>
    </div>
  </section>
</template>

<script>
import axios from "axios";
export default {
  name: "Search",
  data() {
    return {
      keyWord: "",
    };
  },
  methods: {
    //将keyWord作为请求体发送出去
    searchUsers() {
      //假设你vue前端应用跑在8080上，你要发get请求的地址是5050
      axios.get(`http://localhost:8080/github?id=${this.keyWord}`).then(
        (response) => {
          let respData = response.data;
          console.log("请求成功了:", respData);
          this.$bus.$emit("getUsers", respData.users);
        },
        (error) => {
          console.log("请求失败了", error.message);
        }
      );
    },
  },
};
</script>

<style>
</style>