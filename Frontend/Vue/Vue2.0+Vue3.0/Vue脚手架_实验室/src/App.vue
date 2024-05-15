<template>
    <div class="container">
      <Search></Search>
      <List></List>
    </div>
</template>

<script>
import Search from './components/Search.vue';
import List from "./components/List.vue";

export default {
  components: { Search,List },
  name: "App",
};
</script>

<style>

</style>
