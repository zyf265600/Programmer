import { AbstractControl } from "@angular/forms";


export class MyValidators {
    static cannotContainSpace(control: AbstractControl) {
        // 验证未通过
    if (/\s/.test(control.value)) return { cannotContainSpace: true }
    // 验证通过
    return null
    }
}