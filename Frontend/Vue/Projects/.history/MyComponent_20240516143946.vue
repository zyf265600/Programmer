<template>
  <button @click="count++">
    You clicked me {{ count }} times.
  </button>
</template>

<script>
export default {
  data() {
    return {
      count: 0
    }
  }
}
</script>

<style scoped>
/* 你可以在这里添加组件的样式 */
</style>